#include <ESP32Servo.h>

// Define servo pins
int servoPinX = 13;
int servoPinY = 12;

// Create servo objects
Servo servoX;
Servo servoY;

void setup() {
  Serial.begin(115200);
  
  // Attach servos to their respective pins
  servoX.attach(servoPinX);
  servoY.attach(servoPinY);

  // Initialize servos to 0 degrees
  servoX.write(0);
  servoY.write(0);
}

void loop() {
  // Sweep from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle++) {
    servoX.write(angle);
    servoY.write(angle);
    delay(15);  // Small delay to allow the servos to reach the position
  }

  // Sweep back from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle--) {
    servoX.write(angle);
    servoY.write(angle);
    delay(15);  // Small delay to allow the servos to reach the position
  }
}
