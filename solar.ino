#include <Wire.h>
#include <SPI.h>
#include <WiFi.h>
#include <DNSServer.h>
#include <WebServer.h>
#include <ArduCAM.h>
#include <ESP32Servo.h>
#include "webpage.h"
#include "login.h"

// Pin 12 is x Pin 13 is y
Servo SolarServo1;
Servo SolarServo2;
int servoPin1 = 13;
int servoPin2 = 12;

int servo_y = 180;
int servo_x = 180;
const int CS = 5;

// might need to change this value
const int analogPin = 34; // The GPIO pin where the voltage is read

// Structure to hold the timestamp and voltage reading
struct VoltageReading {
    unsigned long timeStamp; // Time of the reading
    float voltage; // Voltage value
} latestReading;

// WiFi Settings for WiFi Mode
const char* wifi_ssid = "Shahomie's Spot";
const char* wifi_password = "Kevo_360_Hot Spot";

// Access Point Settings for AP Mode
const char* ap_ssid = "SunnySideUpgrades_ESP32";
const char* ap_password = "solar_shimmey";

// Define dummy credentials for demonstration purposes
const String adminUsername = "admin";
const String adminPassword = "password";

// Configure IP addresses of the local access point
IPAddress local_IP(192,168,1,22);
IPAddress gateway(192,168,1,5);
IPAddress subnet(255,255,255,0);

WebServer server(80);
ArduCAM myCAM(OV2640, CS);

static const size_t bufferSize = 4096;
static uint8_t buffer[bufferSize] = {0xFF};
uint8_t temp = 0, temp_last = 0;
int i = 0;
bool is_header = false;

float getBatteryPercentage(float voltage) {
  const float lowest = 2.183;
  const float highest = 3.2;

  float percent = 100*((voltage - lowest) / (highest - lowest));

  if(percent <= 0){
    percent = 0;
  }
  if(percent >= 100){
    percent = 100;
  }
  return percent;
}
float voltage = 10.5;
float percent = getBatteryPercentage(voltage);

void handleRoot(){
  server.send_P(200,"text/html",PAGE_MAIN);
}
int servoX = 135; // Initial middle position for X
int servoY = 135; // Initial middle position for Y
void updateServoAngles(int x, int y) {
    // 90 and 180

    // Center of the screen
    int centerX = 240; // X midpoint
    int centerY = 320; // Y midpoint

    int threshold = 10;

    // if the difference of the x value from detection is greater than threshold increment the panel angle accordingly
    if(abs(x-centerX) > threshold || abs(y-centerY) > threshold){
      if(x < centerX){
        servoX += 5;
        }
      if(x > centerX){
        servoX -= 5;
      }
      if(y < centerY){
        servoY += 5;
      }
      if(y > centerY){
        servoY -= 5;
      }
    }

    if(servoY >= 180){
      servoY = 180; 
    }
    if(servoX >= 180){
      servoX = 180;
    }
    if(servoX <= 0){
      servoX = 0;
    }
    if(servoY <= 90){
      servoY = 90;
    }
    SolarServo1.write(servoY);
    SolarServo2.write(servoX);

    Serial.print("Adjusted Servo X to: ");
    Serial.println(servoX);
    Serial.print("Adjusted Servo Y to: ");
    Serial.println(servoY);
}

void handleUpdateCoordinates() {
    if (server.hasArg("x") && server.hasArg("y")) {
        int x = server.arg("x").toInt();
        int y = server.arg("y").toInt();

        updateServoAngles(x, y);

        server.send(200, "text/plain", "Coordinates updated");
    } else {
        server.send(400, "text/plain", "Missing data");
    }
}
void start_capture(){
  myCAM.clear_fifo_flag();
  myCAM.start_capture();
}

void camCapture(ArduCAM myCAM){
  WiFiClient client = server.client();
  uint32_t len  = myCAM.read_fifo_length();
  if (len >= MAX_FIFO_SIZE) //8M
  {
    Serial.println(F("Over size."));
  }
  if (len == 0 ) //0 kb
  {
    Serial.println(F("Size is 0."));
  }
  myCAM.CS_LOW();
  myCAM.set_fifo_burst(); 
  if (!client.connected()) return;
  String response = "HTTP/1.1 200 OK\r\n";
  response += "Content-Type: image/jpeg\r\n";
  response += "Content-len: " + String(len) + "\r\n\r\n";
  server.sendContent(response);
  i = 0;
  while ( len-- )
  {
  temp_last = temp;
  temp =  SPI.transfer(0x00);
  //Read JPEG data from FIFO
  if ( (temp == 0xD9) && (temp_last == 0xFF) ) //If find the end ,break while,
  {
  buffer[i++] = temp;  //save the last  0XD9     
  //Write the remain bytes in the buffer
  if (!client.connected()) break;
  client.write(&buffer[0], i);
  is_header = false;
  i = 0;
  myCAM.CS_HIGH();
  break; 
  }  
  if (is_header == true)
  { 
  //Write image data to buffer if not full
  if (i < bufferSize)
  buffer[i++] = temp;
  else
  {
  //Write bufferSize bytes image data to file
  if (!client.connected()) break;
  client.write(&buffer[0], bufferSize);
  i = 0;
  buffer[i++] = temp;
  }        
  }
  else if ((temp == 0xD8) & (temp_last == 0xFF))
  {
  is_header = true;
  buffer[i++] = temp_last;
  buffer[i++] = temp;   
  } 
  } 
}

void serverCapture(){
    // double check if delay is necessary
    //delay(1000);
  start_capture();

  int total_time = 0;

  total_time = millis();
  while (!myCAM.get_bit(ARDUCHIP_TRIG, CAP_DONE_MASK));
  total_time = millis() - total_time;
  //Serial.print(F("capture total_time used (in miliseconds):"));
  Serial.println(total_time, DEC);

  total_time = 0;

  Serial.println(F("CAM Capture Done."));
  total_time = millis();
  camCapture(myCAM);
  total_time = millis() - total_time;
  Serial.print(F("send total_time used (in miliseconds):"));
  Serial.println(total_time, DEC);
  Serial.println(F("CAM send Done."));
}

void serverStream(){
  WiFiClient client = server.client();

  String response = "HTTP/1.1 200 OK\r\n";
  response += "Content-Type: multipart/x-mixed-replace; boundary=frame\r\n\r\n";
  server.sendContent(response);

  while (1){
  start_capture();
  while (!myCAM.get_bit(ARDUCHIP_TRIG, CAP_DONE_MASK));
  size_t len = myCAM.read_fifo_length();
  if (len >= MAX_FIFO_SIZE) //8M
  {
  Serial.println(F("Over size."));
  continue;
  }
  if (len == 0 ) //0 kb
  {
  Serial.println(F("Size is 0."));
  continue;
  } 
  myCAM.CS_LOW();
  myCAM.set_fifo_burst();
  if (!client.connected()) break;
  response = "--frame\r\n";
  response += "Content-Type: image/jpeg\r\n\r\n";
  server.sendContent(response); 
  while ( len-- )
  {
  temp_last = temp;
  temp =  SPI.transfer(0x00);

  //Read JPEG data from FIFO
  if ( (temp == 0xD9) && (temp_last == 0xFF) ) //If find the end ,break while,
  {
  buffer[i++] = temp;  //save the last  0XD9     
  //Write the remain bytes in the buffer
  myCAM.CS_HIGH();; 
  if (!client.connected()) break;
  client.write(&buffer[0], i);
  is_header = false;
  i = 0;
  }  
  if (is_header == true)
  { 
  //Write image data to buffer if not full
  if (i < bufferSize)
  buffer[i++] = temp;
  else
  {
  //Write bufferSize bytes image data to file
  myCAM.CS_HIGH(); 
  if (!client.connected()) break;
  client.write(&buffer[0], bufferSize);
  i = 0;
  buffer[i++] = temp;
  myCAM.CS_LOW();
  myCAM.set_fifo_burst();
  }        
  }
  else if ((temp == 0xD8) & (temp_last == 0xFF))
  {
  is_header = true;
  buffer[i++] = temp_last;
  buffer[i++] = temp;   
  } 
  }
  if (!client.connected()) break;
  }
}

void handleNotFound(){
  String message = "Server is running!\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  server.send(200, "text/plain", message);
}
void handleLoginRoute() {
    if (server.method() == HTTP_GET) {
        displayLoginPage();
    } else if (server.method() == HTTP_POST) {
        handleLogin();
    }
}
void displayLoginPage() {
    server.send_P(200, "text/html", LOGIN_PAGE);
}
void handleLogin() {
    Serial.println("Handle Called");
    if (server.hasArg("username") && server.hasArg("password")) {
         if (server.arg("username") == "admin" && server.arg("password") == "password") {
                server.sendHeader("Location", "/home", true);
                server.send(302, "text/plain", "");  // Redirect to /home
            } else {
                server.send(401, "text/html", "Unauthorized");  // Invalid credentials
            }
        } else {
            server.send(400, "text/html", "Bad Request");  // Missing username or password
        }
}

// Function to read the voltage from the solar panel
float readVoltage() {
    int rawPanelValue = analogRead(analogPin); // Read the raw analog value
    float voltage = (rawPanelValue / 4095.0) * 3.3; // Convert the analog read value to voltage (0-3.3V)
    float panelVoltage = (voltage / 3.3) * 12.0; // Convert to panel voltage (0-12V)
    Serial.println("Panel Voltage: " + String(panelVoltage));
    return panelVoltage;
}

// Function to store the voltage reading along with the timestamp
void storeReading(float voltage) {
    latestReading = {millis(), voltage};
}

float calculateExtraEnergy() {
    // Simulated or actual method to calculate extra energy
    float standardPanelEnergy = 1200.0; // This could be a standard or expected energy value for comparison
    float actualPanelEnergy = calculateTotalEnergy(); // Actual energy produced

    if (standardPanelEnergy == 0) {
        return 0; // Avoid division by zero
    }

    float extraEnergy = actualPanelEnergy - standardPanelEnergy;
    if (extraEnergy < 0) {
        extraEnergy = 0; // Only consider positive extra energy
    }

    // Convert extra energy to a percentage of the total energy
    float extraEnergyPercentage = (extraEnergy / standardPanelEnergy) * 100;
    return extraEnergyPercentage;
}


float calculateTotalEnergy() {
    float averageCurrent = 10.0;
    return latestReading.voltage * averageCurrent / 1000.0;
}

void handleExtraEnergy() {
    float extraEnergy = calculateExtraEnergy();
    server.send(200, "text/plain", String(extraEnergy));
}

void handleTotalEnergy() {
    float totalEnergy = calculateTotalEnergy();
    server.send(200, "text/plain", String(totalEnergy));
}

  float totalEnergy = 0;
  float panelPower = 0;

void setup() {
  pinMode(34, ANALOG);
  pinMode(35, ANALOG);
  analogReadResolution(12);
  Serial.begin(115200);
  WiFi.begin(wifi_ssid, wifi_password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  //Serial.print("Setting up Access Point ... ");
  //Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");
  //Serial.print("Starting Access Point ... ");
  //Serial.println(WiFi.softAP(ap_ssid, ap_password) ? "Ready" : "Failed!");
  //Serial.print("IP address = ");
  //Serial.println(WiFi.softAPIP());  
  uint8_t vid, pid;
  uint8_t temp;
  pinMode(CS, OUTPUT);

  // I2C START SDA, SCL
  Wire.begin(21, 22);

  // Initialize SPI: SCK, MISO, MOSI, SS
  SPI.begin(18, 19, 23, 5);
  SPI.setFrequency(4000000); //4MHz

  // Check if the ArduCAM SPI bus is OK
  myCAM.write_reg(ARDUCHIP_TEST1, 0x55);
  temp = myCAM.read_reg(ARDUCHIP_TEST1);
  if (temp != 0x55) {
      Serial.println(F("SPI1 interface Error!"));
      while(1);
  }

  //Check if the camera module type is OV2640
  myCAM.wrSensorReg8_8(0xff, 0x01);
  myCAM.rdSensorReg8_8(OV2640_CHIPID_HIGH, &vid);
  myCAM.rdSensorReg8_8(OV2640_CHIPID_LOW, &pid);
  if ((vid != 0x26 ) && (( pid != 0x41 ) || ( pid != 0x42 )))
  Serial.println(F("Can't find OV2640 module!"));
  else
  Serial.println(F("OV2640 detected."));


  //Change to JPEG capture mode and initialize the OV2640 module
  myCAM.set_format(JPEG);
  myCAM.InitCAM();

  myCAM.OV2640_set_JPEG_size(OV2640_640x480);
  myCAM.clear_fifo_flag();



      // Start the server
      server.on("/home",handleRoot);
      server.on("/login", handleLoginRoute);
      server.on("/capture", HTTP_GET, serverCapture);
      server.on("/stream", HTTP_GET, serverStream);
      server.on("/update_coordinates", HTTP_POST, handleUpdateCoordinates);
      server.onNotFound(handleNotFound);
      // server.on("/extra_energy", handleExtraEnergy);
      // Adjusted function to send the extra energy as a percentage
      server.on("/extra_energy", HTTP_GET, []() {
        int rawValue = analogRead(34);  // Read the current voltage from the solar panel
        float panelVoltage = (rawValue / 4095.0) * 12.0;  // Convert raw reading directly to panel voltage
        float panelPower = panelVoltage * panelVoltage / 1.2; // live power reading using V^2/R
        server.send(200, "text/plain", String(panelPower, 2));  // Send live power reading as text
      });

      server.on("/total_energy", HTTP_GET, []() {
        float energyIncrement = panelPower * (10.0 / 3600.0);  // Convert power (W) to energy (Wh) for 10 seconds
        totalEnergy += energyIncrement;  // Accumulate the total energy in Wh
        server.send(200, "text/plain", String(totalEnergy, 2));  // Send total energy in Wh as plain text
      });

      server.on("/battery", HTTP_GET, []() {
        int rawValue = analogRead(35); // Read the current voltage
        float voltage = rawValue / 4095.0 * 3.3; // Convert raw reading to voltage
        float percent = getBatteryPercentage(voltage); // Calculate current battery percentage
    
        server.send(200, "text/plain", String(percent)); // Send updated percentage
      });
    
      server.on("/ip", HTTP_GET, []() {
        server.send(200, "text/plain", WiFi.localIP().toString());
        Serial.println("This is getting sent to the webapp:" + WiFi.localIP());
      });

      server.onNotFound([]() {
      server.send(404, "text/plain", "404: Not found");
      });
    
      server.begin();
      Serial.println(F("Server started"));

  SolarServo1.attach(servoPin1);
  SolarServo1.write(135);
  SolarServo2.attach(servoPin2);
  SolarServo2.write(135);
  }
  
  unsigned long previousMillis = 0; // Stores the last time the average was output
  const long interval = 1000; // Interval at which to attempt reading the average (milliseconds)

  // Variables for handling the averaging process
  const int readingsToCollect = 500;
  int readingsCount = 0;
  long readingsSum = 0;
  
void loop() {
    server.handleClient();

    //Serial.println(WiFi.softAPIP());

    //Serial.println(WiFi.localIP());
    
    if (Serial.available() > 0) {
          String command = Serial.readStringUntil('\n');
          command.trim();

          if (command.startsWith("X")) {
              int angle = command.substring(1).toInt();
              if (angle >= 0 && angle <= 180) {
                  servo_x = angle;
                  SolarServo2.write(servo_x);
                  Serial.print("Servo X set to: ");
                  Serial.println(servo_x);
              } else {
                  Serial.println("Invalid angle for Servo X");
              }
          }
          else if (command.equals("R")){
            servo_x = 135;
            servo_y = 135;
            SolarServo2.write(servo_x);
            SolarServo1.write(servo_y);
            Serial.print("Adjusted Servo X to: ");
            Serial.println(servoX);
            Serial.print("Adjusted Servo Y to: ");
            Serial.println(servoY);

          }
          else if (command.startsWith("Y")) {
              int angle = command.substring(1).toInt();
              if (angle >= 90 && angle <= 180) {
                  servo_y = angle;
                  SolarServo1.write(servo_y);
                  Serial.print("Servo Y set to: ");
                  Serial.println(servo_y);
              } else {
                  Serial.println("Invalid angle for Servo Y");
              }
          } else {
              Serial.println("Invalid command");
          }
      }
 /*
    // Always collect readings, independent of the timing for output
    if (readingsCount < readingsToCollect) {
      int rawValue = analogRead(35);
      readingsSum += rawValue; // Add the raw value to the sum
      readingsCount++; // Increment the count of readings
    }
    
    unsigned long currentMillis = millis();
    
    // If we have collected 500 readings and the interval has passed, calculate and display the average
    if (readingsCount >= readingsToCollect && (currentMillis - previousMillis >= interval)) {
      float averageRawValue = (float)readingsSum / readingsCount;
      float averageVoltage = averageRawValue / 4095.0 * 3.3;
      
      Serial.print("Average Raw Value: ");
      Serial.println(averageRawValue);
      Serial.print("Average Voltage: ");
      Serial.println(averageVoltage);
      
      
      // Reset for the next averaging cycle
      readingsSum = 0;
      readingsCount = 0;
      previousMillis = currentMillis; // Update the time we last output the average

    }
    */
    
    static unsigned long lastReadTime = 0; // Last time the voltage was read
      const long interval = 5000; // Interval between reads, 1 hour in milliseconds

      unsigned long currentTime = millis(); // Get the current time
        if (currentTime - lastReadTime >= interval) { // Check if the interval has passed
          float voltage = readVoltage(); // Read the current voltage
          storeReading(voltage); // Store the reading
          lastReadTime = currentTime; // Update the last read time
        
          Serial.print("Latest Voltage Reading: ");
          Serial.println(latestReading.voltage);
        }

    }
                   
