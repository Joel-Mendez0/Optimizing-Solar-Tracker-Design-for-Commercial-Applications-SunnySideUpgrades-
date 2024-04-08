import cv2
import numpy as np
import requests
import time

ESP32_IP_ADDRESS = ""
IMAGE_URL = f"http://{ESP32_IP_ADDRESS}/capture"

def draw_dividing_boxes(image):
    color = (255, 0, 0)  # Blue color in BGR
    thickness = 1
    height, width, _ = image.shape

    for i in range(1, 10):  # Draw vertical lines
        cv2.line(image, (i * width // 10, 0), (i * width // 10, height), color, thickness)
    for j in range(1, 10):  # Draw horizontal lines
        cv2.line(image, (0, j * height // 10), (width, j * height // 10), color, thickness)

def send_coordinates_to_esp32(middle_x, middle_y):
    url = f"http://{ESP32_IP_ADDRESS}/update_coordinates"
    data = {'x': middle_x, 'y': middle_y}
    try:
        response = requests.post(url, data=data)
        print(f"Response from ESP32: {response.text}")
    except requests.exceptions.RequestException as e:
        print(f"Error sending data to ESP32: {e}")

def find_brightest_area(image):
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    _, thresh = cv2.threshold(gray, 240, 255, cv2.THRESH_BINARY)
    contours, _ = cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    if not contours:
        return None

    max_contour = max(contours, key=cv2.contourArea)
    if cv2.contourArea(max_contour) > 0:
        M = cv2.moments(max_contour)
        middle_x = int(M["m10"] / M["m00"])
        middle_y = int(M["m01"] / M["m00"])
        x, y, w, h = cv2.boundingRect(max_contour)
        cv2.rectangle(image, (x, y), (x + w, y + h), (0, 255, 0), 2)
        return (middle_x, middle_y)
    else:
        return None

def fetch_image(url, retries=3):
    attempt = 0
    while attempt < retries:
        response = requests.get(url)
        if response.status_code == 200:
            image_data = np.asarray(bytearray(response.content), dtype="uint8")
            image = cv2.imdecode(image_data, cv2.IMREAD_COLOR)
            if image is not None:
                return image
            else:
                print(f"Received empty buffer, retrying ({attempt + 1}/{retries})...")
        else:
            print(f"Failed to fetch image, HTTP status code: {response.status_code}")

        attempt += 1
        time.sleep(1)  # wait a bit before retrying

    return None

if __name__ == "__main__":
    try:
        while True:
            start_time = time.time()
            image = fetch_image(IMAGE_URL)
            if image is not None:
                draw_dividing_boxes(image)
                middle_coordinates = find_brightest_area(image)

                if middle_coordinates is not None:
                    print(f"Middle Coordinates: {middle_coordinates}")
                    send_coordinates_to_esp32(*middle_coordinates)
                    end_time = time.time()
                    duration_ms = (end_time - start_time) * 1000
                    print(f"Time taken: {duration_ms:.2f} ms")

                cv2.imshow('Image', image)
                if cv2.waitKey(1) & 0xFF == ord('q'):
                    break
            else:
                print("Error fetching image from URL")

    except Exception as e:
        print(f"Error: {e}")

    finally:
        cv2.destroyAllWindows()
