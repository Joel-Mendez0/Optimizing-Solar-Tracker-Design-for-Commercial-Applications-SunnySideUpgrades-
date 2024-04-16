#include <vector>

// might need to change this value
const int analogPin = 35; // The GPIO pin where the voltage is read

// Structure to hold the timestamp and voltage reading
struct VoltageReading {
    unsigned long timeStamp; // Time of the reading
    float voltage; // Voltage value
};

VoltageReading latestReading; // Variable to store the latest reading

// Function to read the voltage from the solar panel
float readVoltage() {
    int rawPanelValue = analogRead(analogPin); // Read the raw analog value
    float voltage = (rawPanelValue / 4095.0) * 3.3; // Convert the analog read value to voltage (0-3.3V)
    float panelVoltage = (voltage / 3.3) * 12.0; // Convert to panel voltage (0-12V)
    return panelVoltage;
}

// Function to store the voltage reading along with the timestamp
void storeReading(float voltage) {
    readings.push_back({millis(), voltage});
}

float calculateExtraEnergy() {
    float standardPanelEnergy = 0.0;
    float myPanelEnergy = 0.0;
    float averageCurrent = 10.0; // Example current value in Amperes

    for (const auto& reading : readings) {
        float standardPanelVoltage = reading.voltage / 1.5; // Assuming 50% more efficient means 1.5 times the voltage
        standardPanelEnergy += standardPanelVoltage * averageCurrent / 1000.0; // Wh for each hour
        myPanelEnergy += reading.voltage * averageCurrent / 1000.0; // Wh for each hour
    }

    float extraEnergy = (myPanelEnergy - standardPanelEnergy) / 24.0; // Convert to kWh assuming readings are hourly
    return extraEnergy;
}


float calculateTotalEnergy() {
    // Assuming we have stored each hour's voltage in the readings vector and have a constant current
    float totalEnergy = 0.0;
    float averageCurrent = 10.0; // Example current value in Amperes

    for (const auto& reading : readings) {
        totalEnergy += reading.voltage * averageCurrent / 1000.0; // Wh for each hour
    }

    return totalEnergy / 24.0; // Convert to kWh assuming readings are hourly
}

void handleExtraEnergy() {
    float extraEnergy = calculateExtraEnergy();
    server.send(200, "text/plain", String(extraEnergy));
}

void handleTotalEnergy() {
    float totalEnergy = calculateTotalEnergy();
    server.send(200, "text/plain", String(totalEnergy));
}

// Arduino setup function, runs once at startup
void setup() {
    Serial.begin(115200); // Start the serial communication
    pinMode(analogPin, INPUT); // Set the analog pin as input

    server.on("/extra_energy", handleExtraEnergy);
    server.on("/total_energy", handleTotalEnergy);


}

// Arduino main loop function, runs repeatedly
void loop() {

    // add new readings to SD card
    static unsigned long lastReadTime = 0; // Last time the voltage was read
    const long interval = 3600000; // Interval between reads, 1 hour in milliseconds

    unsigned long currentTime = millis(); // Get the current time
    if (currentTime - lastReadTime >= interval) { // Check if the interval has passed
        float voltage = readVoltage(); // Read the current voltage
        storeReading(voltage); // Store the reading
        lastReadTime = currentTime; // Update the last read time
        
        Serial.print("Latest Voltage Reading: ");
        Serial.println(latestReading.voltage);
        }
    }
}
