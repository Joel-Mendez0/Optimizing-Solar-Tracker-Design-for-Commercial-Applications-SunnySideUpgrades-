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

int servoX = 135;
int servoY = 135;
const int CS = 5;

const int batteryPin = 36;
const int panelPin = 39;

float panelPower;
float totalEnergy = 0;

// WiFi Settings for WiFi Mode
const char* wifi_ssid = "Shahomie's Spot";
const char* wifi_password = "Kevo_360_Hot Spot";

// Define dummy credentials for demonstration purposes
const String adminUsername = "admin";
const String adminPassword = "password";

// Configure IP addresses of the local access point
IPAddress local_IP(192,168,4,1);
IPAddress gateway(192,168,4,1);
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
  const float highest = 3;

  float percent = 100*((voltage - lowest) / (highest - lowest));

  if(percent <= 0){
    percent = 0;
  }
  if(percent >= 100){
    percent = 100;
  }
  return percent;
}

void handleRoot(){
  server.send_P(200,"text/html",PAGE_MAIN);
}

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

void setup() {
  Serial.begin(115200);  // Start Serial communication at 115200 baud rate
  pinMode(batteryPin, INPUT_PULLDOWN);  // Set GPIO 25 as input with internal pull-down resistor enabled
  pinMode(panelPin, INPUT_PULLDOWN);  // Set GPIO 14 as input with internal pull-down resistor enabled
  analogReadResolution(12);  // Set the resolution to 12 bits (0-4095)
  analogSetAttenuation(ADC_11db);  // Set attenuation to read max voltage ~3.3V

  SolarServo1.attach(servoPin1);
  SolarServo1.write(servoY);
  SolarServo2.attach(servoPin2);
  SolarServo2.write(servoX);
  
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

  WiFi.begin(wifi_ssid, wifi_password);
  while (WiFi.status() != WL_CONNECTED) {
   delay(1000);
   Serial.print(".");
  }
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Start the server
  server.on("/home", handleRoot);
  server.on("/login", handleLoginRoute);
  server.on("/capture", HTTP_GET, serverCapture);
  server.on("/stream", HTTP_GET, serverStream);
  server.on("/update_coordinates", HTTP_POST, handleUpdateCoordinates);
  server.onNotFound(handleNotFound);

  server.on("/energy_data", HTTP_GET, [](){

    int rawPanel = analogRead(panelPin);  // Read the current voltage from the solar panel
    float panelVoltage = (rawPanel / 4095.0) * 12.0; // Convert raw reading to voltage
    panelPower = panelVoltage * panelVoltage / 1.2; // Calculate power using V^2/R

    float energyIncrement = panelPower * (0.5 / 3600.0); // Convert power to energy (Wh) for every half second
    totalEnergy += energyIncrement; // Accumulate total energy in Wh

    // Manually create JSON string
    char response[200];
    snprintf(response, sizeof(response), "{\"panelPower\": %.2f, \"totalEnergy\": %.2f}", panelPower, totalEnergy);

    Serial.print("Panel Power:");
    Serial.println(panelPower);
    Serial.print("Total Energy:");
    Serial.println(totalEnergy);
    server.send(200, "application/json", response);  // Send the JSON response
  });

  server.on("/battery", HTTP_GET, []() {

    int rawBattery = analogRead(batteryPin); // Read the current voltage
    float batteryVoltage = rawBattery / 4095.0 * 3.3; // Convert raw reading to voltage
    float batteryPercent = getBatteryPercentage(batteryVoltage); // Calculate current battery percentage
    Serial.println("Battery Percentage: " + String(batteryPercent));
    server.send(200, "text/plain", String(batteryPercent)); // Send updated percentage
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
}

void loop() {

  server.handleClient();

  if (Serial.available() > 0) {
      String command = Serial.readStringUntil('\n');
      command.trim();

      if (command.startsWith("X")) {
          int angle = command.substring(1).toInt();
          if (angle >= 0 && angle <= 180) {
              servoX = angle;
              SolarServo2.write(servoX);
              Serial.print("Servo X set to: ");
              Serial.println(servoX);
          } else {
              Serial.println("Invalid angle for Servo X");
          }
      }
      else if (command.equals("R")){
        servoX = 135;
        servoY = 135;
        SolarServo2.write(servoX);
        SolarServo1.write(servoY);
        Serial.print("Adjusted Servo X to: ");
        Serial.println(servoX);
        Serial.print("Adjusted Servo Y to: ");
        Serial.println(servoY);

      }
      else if (command.startsWith("Y")) {
          int angle = command.substring(1).toInt();
          if (angle >= 90 && angle <= 180) {
              servoY = angle;
              SolarServo1.write(servoY);
              Serial.print("Servo Y set to: ");
              Serial.println(servoY);
          } else {
              Serial.println("Invalid angle for Servo Y");
          }
      } else {
          Serial.println("Invalid command");
      }
    }

}
