// Include the libraries for the sensors
#include <DHT.h>

// Set the pin numbers for the sensors
const int soilMoisturePin = A0;
const int DHT11Pin = 2;
const int pHsensorPin = A1;

// Create the objects for the sensors
DHT dht(DHT11Pin, DHT11);

// Set up the initial variables
int soilMoistureValue = 0;
float temperatureValue = 0;
float humidityValue = 0;
int pHsensorValue = 0;

// Set up counter variables
int moistureCount = 0;
int tempCount = 0;
int humCount = 0;
int pHCount = 0;

void setup() {
  // Start the serial communication
  Serial.begin(9600);

  // Initialize the sensors
  dht.begin();
}

void loop() {
  // Read the values from the sensors if the count is less than 30
  if (moistureCount < 30) {
    soilMoistureValue = analogRead(soilMoisturePin);
    moistureCount++;
  }

  if (tempCount < 30) {
    temperatureValue = dht.readTemperature();
    tempCount++;
  }

  if (humCount < 30) {
    humidityValue = dht.readHumidity();
    humCount++;
  }

  if (pHCount < 30) {
    pHsensorValue = analogRead(pHsensorPin);
    pHCount++;
  }

  // Convert the soil moisture sensor value to a percentage
  float soilMoisturePercentage = map(soilMoistureValue, 0, 1023, 0, 100);

  // Map the pH sensor value from the range of 0-1023 to 0-10
  float phValue = map(pHsensorValue, 0, 1023, 0, 10);

  // Display the values on the serial monitor
  Serial.print(soilMoisturePercentage);
  Serial.print(",");
  Serial.print(temperatureValue);
  Serial.print(",");
  Serial.print(humidityValue);
  Serial.print(",");
  Serial.print(phValue, 2);
  Serial.println();

  // Stop reading values from each sensor after 30 readings
  if (moistureCount == 20 && tempCount == 20 && humCount == 20 && pHCount == 20) {
    while (1); // Infinite loop to stop the program
  }

  // Delay for 2 seconds before reading the sensors again
  delay(3000);
}
