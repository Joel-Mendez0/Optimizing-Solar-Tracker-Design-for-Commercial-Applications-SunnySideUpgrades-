import cv2
import numpy as np
import threading
import time

class WebcamThread(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
        self.cap = cv2.VideoCapture(0)
        self.cap.set(cv2.CAP_PROP_FPS, 30)  # Set FPS to 30
        self.frame = None
        self.running = True

    def run(self):
        while self.running:
            ret, frame = self.cap.read()
            if ret:
                self.frame = frame

    def stop(self):
        self.running = False
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

    # Create a mask to highlight the brightest area
    mask = np.zeros_like(gray)
    cv2.drawContours(mask, [max_contour], 0, 255, -1)

    # Bitwise AND the original frame with the mask
    result = cv2.bitwise_and(frame, frame, mask=mask)

    return result

if __name__ == "__main__":
    webcam_thread = WebcamThread()
    webcam_thread.start()

    try:
        while True:
            frame = webcam_thread.frame

            if frame is not None:
                # Find the brightest area in the current frame
                result = find_brightest_area(frame)

                if result is not None:
                    # Display the original frame and the result
                    cv2.imshow('Original Frame', frame)
                    cv2.imshow('Brightest Area', result)

            # Check for key events
            key = cv2.waitKey(1)
            if key & 0xFF == ord('q'):
                break

            # Wait for 1 millisecond
            time.sleep(0.001)

    except Exception as e:
        print(f"Error: {e}")

    finally:
        webcam_thread.stop()
        webcam_thread.join()

        # Close windows
        cv2.destroyAllWindows()
