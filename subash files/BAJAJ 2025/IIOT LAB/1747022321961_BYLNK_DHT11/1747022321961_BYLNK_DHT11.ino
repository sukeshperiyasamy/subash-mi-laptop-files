
#define BLYNK_TEMPLATE_ID "TMPL3RlCxLaHQ"
#define BLYNK_TEMPLATE_NAME "TEMPERATURE AND HUMIDITY"
#define BLYNK_AUTH_TOKEN "FdN2iSPUnCdT8zEBylGVykTczyz7Zgjk"

#define BLYNK_PRINT Serial
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>FER
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "nithi";  // type your wifi name
char pass[] = "nithish888";  // type your wifi password
#define DHTPIN 26          // Mention the digital pin where you connected 
#define DHTTYPE DHT11     // DHT 11  
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor(){
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
    Blynk.virtualWrite(V0, t);
    Blynk.virtualWrite(V1, h);
    Serial.print("Temperature : ");
    Serial.println(t);
    Serial.print("    Humidity : ");
    Serial.println(h);
  }
void setup(){
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  //pinMode(DHTPIN,OUTPUT);
  timer.setInterval(1000L, sendSensor);
}
void loop(){
  Blynk.run();
  timer.run();
}
