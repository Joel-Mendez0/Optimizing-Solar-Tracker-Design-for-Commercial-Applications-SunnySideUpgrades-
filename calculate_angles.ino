#include <Arduino.h>
#include <ImageProcessing.h>

// Define image dimensions
const int width = 320;
const int height = 240;

// Image arrays
byte rgbImage[width * height * 3];
byte grayscaleImage[width * height];
byte thresholdedImage[width * height];

void convertToGrayscale(byte* rgbImage, byte* grayscaleImage, int width, int height) {
  for (int i = 0; i < width * height * 3; i += 3) {
    // Calculate the average of red, green, and blue values
    grayscaleImage[i / 3] = (rgbImage[i] + rgbImage[i + 1] + rgbImage[i + 2]) / 3;
  }
}

void applyThreshold(byte* grayscaleImage, byte* thresholdedImage, int width, int height, byte threshold) {
  for (int i = 0; i < width * height; i++) {
    // Apply threshold
    thresholdedImage[i] = (grayscaleImage[i] > threshold) ? 255 : 0;
  }
}

void calculate_angles(int middle_x, int middle_y){
   angle_1 = 0;
   angle_2 = 0;
}

void setup() {
  // Your setup code here
}

void loop() {
  // Your main code here

  // Capture RGB image (replace this with your actual image capture code)
  // For simplicity, a placeholder is used here
  for (int i = 0; i < width * height * 3; i++) {
    rgbImage[i] = random(256);
  }

  // Convert RGB image to grayscale
  convertToGrayscale(rgbImage, grayscaleImage, width, height);

  // Apply threshold to the grayscale image
  byte thresholdValue = 128;  // Adjust threshold as needed
  applyThreshold(grayscaleImage, thresholdedImage, width, height, thresholdValue);

  // Assuming you have the "Arduino Image Processing Toolbox" library installed and configured
  ImageProcessing image;

  // Find contours in the binary image
  image.setImage(thresholdedImage, width, height);
  image.findContours();

  // Get the number of contours
  int contourCount = image.getContourCount();

  if (contourCount > 0) {
    // Find the contour with the largest area
    int maxContourIndex = 0;
    int maxContourArea = image.getContourArea(0);

    for (int i = 1; i < contourCount; i++) {
      int area = image.getContourArea(i);
      if (area > maxContourArea) {
        maxContourArea = area;
        maxContourIndex = i;
      }
    }

    // Check if the contour has a non-zero area
    if (maxContourArea > 0) {
      // Calculate the middle coordinates of the highlighted region
      int middle_x = image.getContourCenterX(maxContourIndex);
      int middle_y = image.getContourCenterY(maxContourIndex);

      // Draw bounding box around the region
      int x, y, w, h;
      image.getBoundingBox(maxContourIndex, x, y, w, h);
      // Now, you can use x, y, w, and h to draw a rectangle on your display

      // Do something with the middle coordinates (middle_x, middle_y)
      calculate_angles(int middle_x, int middle_y);
      
      // Code to Write the Angles to the panel
      
    }
  }
}

