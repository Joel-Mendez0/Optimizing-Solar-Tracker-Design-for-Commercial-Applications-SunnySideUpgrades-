import cv2
import numpy as np
import time

class WebcamCapture:
    def __init__(self):
        self.cap = cv2.VideoCapture(0)
        self.cap.set(cv2.CAP_PROP_FPS, 24)  # Set FPS to 24

    def capture_frame(self):
        ret, frame = self.cap.read()
        if ret:
            return frame
        else:
            return None

    def release(self):
        self.cap.release()

def find_brightest_area(frame):
    # Convert the frame to grayscale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

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
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)

        return (middle_x, middle_y)
    else:
        return None

def calculate_motor_angles(middle_x, middle_y):
    motor_1_angle = 0
    motor_2_angle = 0
    return motor_1_angle, motor_2_angle

if __name__ == "__main__":
    try:
        webcam_capture = WebcamCapture()

        while True:
            frame = webcam_capture.capture_frame()

            if frame is not None:
                middle_coordinates = find_brightest_area(frame)

                if middle_coordinates is not None:
                    print(f"Middle Coordinates: {middle_coordinates}")

                # Show the frame
                cv2.imshow('Frame', frame)

                # Wait for a key press and close the window if 'q' is pressed
                if cv2.waitKey(1) & 0xFF == ord('q'):
                    break

    except Exception as e:
        print(f"Error: {e}")

    finally:
        webcam_capture.release()
        cv2.destroyAllWindows()
