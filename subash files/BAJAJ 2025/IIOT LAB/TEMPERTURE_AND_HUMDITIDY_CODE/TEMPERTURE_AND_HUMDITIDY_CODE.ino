
#include <DHT.h>

#define DHTPIN 2        // Pin where the DHT11 is connected
#define DHTTYPE DHT11   // Define the sensor type

DHT subash(DHTPIN, DHTTYPE);  // Create DHT object

void setup() 
{
  Serial.begin(115200);  // Initialize serial communication
  subash.begin();        // Initialize the DHT sensor
}

void loop() 
{
  float h = subash.readHumidity();      // Read humidity
  float t = subash.readTemperature();   // Read temperature in Celsius

  if (isnan(h) || isnan(t))  // Check if reading failed
  {
    Serial.println("Sensor failed to read data!");
    return;
  }

  Serial.print("HUMIDITY: ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("TEMPERATURE: ");
  Serial.println(t);
}


