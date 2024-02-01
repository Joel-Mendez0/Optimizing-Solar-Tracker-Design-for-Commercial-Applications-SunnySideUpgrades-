import cv2
import numpy as np
import requests
import time

ESP32_IP_ADDRESS = "IP_ADDRESS"

IMAGE_URL = f"http://{ESP32_IP_ADDRESS}/capture"

def send_coordinates_to_esp32(middle_x, middle_y):
    url = f"http://{ESP32_IP_ADDRESS}/update_coordinates"
    data = {'x': middle_x, 'y': middle_y}
    try:
        response = requests.post(url, data=data)
        print(f"Response from ESP32: {response.text}")
    except requests.exceptions.RequestException as e:
        print(f"Error sending data to ESP32: {e}")

def find_brightest_area(image):
    # Convert the image to grayscale
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Find the brightest region
    _, thresh = cv2.threshold(gray, 240, 255, cv2.THRESH_BINARY)

    # Find contours in the binary image
    contours, _ = cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    if not contours:
        return None

    # Find the contour with the largest area (brightest region)
    max_contour = max(contours, key=cv2.contourArea)

    # Check if the contour has a non-zero area
    if cv2.contourArea(max_contour) > 0:
        # Calculate the middle coordinates of the highlighted region
        M = cv2.moments(max_contour)
        middle_x = int(M["m10"] / M["m00"])
        middle_y = int(M["m01"] / M["m00"])

        # Draw bounding box around the region
        x, y, w, h = cv2.boundingRect(max_contour)
        cv2.rectangle(image, (x, y), (x + w, y + h), (0, 255, 0), 2)

        return (middle_x, middle_y)
    else:
        return None

def fetch_image(url):
    response = requests.get(url)
    if response.status_code == 200:
        image = np.asarray(bytearray(response.content), dtype="uint8")
        image = cv2.imdecode(image, cv2.IMREAD_COLOR)
        return image
    else:
        return None

if __name__ == "__main__":
    try:
        while True:
            image = fetch_image(IMAGE_URL)

            if image is not None:
                middle_coordinates = find_brightest_area(image)

                if middle_coordinates is not None:
                    print(f"Middle Coordinates: {middle_coordinates}")
                    send_coordinates_to_esp32(*middle_coordinates)

                # Show the image
                cv2.imshow('Image', image)
                if cv2.waitKey(1) & 0xFF == ord('q'):
                    break
            else:
                print("Error fetching image from URL")

            #time.sleep(0.5)  # Delay for 0.5 seconds

    except Exception as e:
        print(f"Error: {e}")

    finally:
        cv2.destroyAllWindows()

