#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Replace with your network credentials
char auth[] = "YOUR_BLYNK_AUTH_TOKEN";
char ssid[] = "123123";
char pass[] = "12312311";

// Pin connected to the relay module
#define RELAY_PIN 4

void setup() {
  Serial.begin(9600);

  // Connect to Wi-Fi
  Blynk.begin(auth, ssid, pass);

  // Set the relay pin as an output
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  Blynk.run();
}

// Blynk Virtual Button Widget callback
BLYNK_WRITE(V0) {
  int value = param.asInt();
  if (value == 1) {
    // Turn on the bulb (close the relay)
    digitalWrite(RELAY_PIN, HIGH);
  } else {
    // Turn off the bulb (open the relay)
    digitalWrite(RELAY_PIN, LOW);
  }
}