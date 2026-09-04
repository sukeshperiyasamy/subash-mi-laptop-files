#include <Servo.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

Servo servo1;
Servo servo2;

#define BLYNK_TEMPLATE_ID "TMPL3hcIu5AAD"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "ZhfvpLhZcT3GH5sWt1IqSu-W-yQSMIlv"

char auth[] = BLYNK_AUTH_TOKEN;  
char ssid[] = "sukeshsubash";   
char pass[] = "sukesh9595"; 

BlynkTimer timer;

// Button states for four positions
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;
int buttonState7 = 0;
int buttonState8 = 0;
void setup() {
  servo1.attach(D0);
  servo2.attach(D1);
  
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  Blynk.virtualWrite(V0, buttonState1);
  Blynk.virtualWrite(V1, buttonState2);
  Blynk.virtualWrite(V2, buttonState3);
  Blynk.virtualWrite(V3, buttonState4);
  Blynk.virtualWrite(V4, buttonState5);
  Blynk.virtualWrite(V5, buttonState6);
  Blynk.virtualWrite(V6, buttonState7);
  Blynk.virtualWrite(V7, buttonState8);
  timer.setInterval(100L, servoControl); 
}

void loop() {
  Blynk.run();
  timer.run();
}

void servoControl() {
  if (buttonState1 == HIGH) {
    servo1.write(45);
    delay(1000);
  }
  else if (buttonState2 == HIGH) {
    servo1.write(90);
    delay(1000);
  }
  else if (buttonState3 == HIGH) {
    servo1.write(135);
    delay(1000);
  }
  else if (buttonState4 == HIGH) {
    servo1.write(180);
    delay(1000);
  }
  else if (buttonState5 == HIGH) {
    servo2.write(45);
    delay(1000);
  }
  else if (buttonState6 == HIGH) {
    servo2.write(90);
    delay(1000);
  }
  else if (buttonState7 == HIGH) {
    servo2.write(135);
    delay(1000);
  }
  else if (buttonState8 == HIGH) {
    servo2.write(180);
    delay(1000);
  }
  else {
    servo1.write(0);
    servo2.write(0);
  }
}

BLYNK_WRITE(V0) {
  buttonState1 = param.asInt();
}

BLYNK_WRITE(V1) {
  buttonState2 = param.asInt();
}

BLYNK_WRITE(V2) {
  buttonState3 = param.asInt();
}

BLYNK_WRITE(V3) {
  buttonState4 = param.asInt();
}

BLYNK_WRITE(V4) {
  buttonState5 = param.asInt();
}

BLYNK_WRITE(V5) {
  buttonState6 = param.asInt();
}

BLYNK_WRITE(V6) {
  buttonState7 = param.asInt();
}

BLYNK_WRITE(V7) {
  buttonState8 = param.asInt();
}