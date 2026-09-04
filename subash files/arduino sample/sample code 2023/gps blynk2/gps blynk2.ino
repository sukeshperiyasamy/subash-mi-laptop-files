#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

#define BLYNK_TEMPLATE_ID "TMPL34Wey_jPt"
#define BLYNK_TEMPLATE_NAME "Sanjay"
#define BLYNK_AUTH_TOKEN "F1o8ADZXrjETixhL7YLQKE7e-EwWeCEb"


char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "123123";
char pass[] = "12312312";

SoftwareSerial gpsSerial(4, 5); // Connect GPS TX to D4 and RX to D5
TinyGPSPlus gps;

BLYNK_WRITE(V0) {
 int speedLimit = param.asInt(); 
}

void setup() {
Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
 gpsSerial.begin(9600); 
 Serial.begin(9600); 

}

void loop() {
 Blynk.run();
Serial.println("Speed: " + String(gps.speed.kmph()) + " km/h");
 while (gpsSerial.available() > 0) {
   if (gps.encode(gpsSerial.read())) {
    Serial.println("Speed: " + String(gps.speed.kmph()) + " km/h");
     if (gps.speed.kmph() > 60) { 
       Blynk.virtualWrite(V1, "Speed Warning: " + String(gps.speed.kmph()) + " km/h");
       

       // Create and send the Google Maps URL
       String googleMapsURL = "https://www.google.com/maps?q=" + String(gps.location.lat(), 6) + "," + String(gps.location.lng(), 6);
       Blynk.virtualWrite(V2, googleMapsURL);

      Serial.println("Speed: " + String(gps.speed.kmph()) + " km/h");
       Serial.println("Latitude: " + String(gps.location.lat(), 6));
       Serial.println("Longitude: " + String(gps.location.lng(), 6));
       Serial.println("Google Maps URL: " + googleMapsURL);


       
     }
   }
 }
}