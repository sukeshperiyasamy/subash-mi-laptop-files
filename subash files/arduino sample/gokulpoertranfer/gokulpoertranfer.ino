#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define Sensor1 34
#define Sensor2 35

const int motorPin1 = 12;
const int motorPin2 = 13;
const int motorPin3 = 14;
const int motorPin4 = 27;

float vOUT1 = 0.0;
float vIN1 = 0.0;
float vOUT2 = 0.0;
float vIN2 = 0.0;
float R1 = 30000.0;
float R2 = 7500.0;

int x = 50;
int y = 50;

#define BLYNK_TEMPLATE_ID "TMPL3pa_shCeh" 
#define BLYNK_TEMPLATE_NAME "CH3" 
#define BLYNK_AUTH_TOKEN "A9QGVrqCljpF5Vy_4kB39duDwQcTk9U4"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "123123";
char pass[] = "12312312";

void setup() {
  Serial.begin(9600);

  // Set the motor pins as output pins
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  // Initialize the Blynk library
  Blynk.begin(auth, ssid, pass);
}

// Get the joystick values
BLYNK_WRITE(V0) {
  x = param[0].asInt();
}

// Get the joystick values
BLYNK_WRITE(V1) {
  y = param[0].asInt();
}

void smartcar() {
  if (y > 70) {
    carForward(255);
    
  } else if (y < 30) {
    carBackward(255);
    Serial.println("carBackward");
  } else if (x < 30) {
    carLeft(255);
   
  } else if (x > 70) {
    carRight(255);
    
  } else if (x < 70 && x > 30 && y < 70 && y > 30) {
    carStop(0);

  }
}

void loop() {
  Blynk.run();
  smartcar();

  int value1 = analogRead(Sensor1);
  vOUT1 = (value1 * 3.3) / 4095.0;
  vIN1 = vOUT1 / (R2 / (R1 + R2));

  int value2 = analogRead(Sensor2);
  vOUT2 = (value2 * 3.3) / 4095.0;
  vIN2 = vOUT2 / (R2 / (R1 + R2));

  
  
  Serial.println(vIN2);

  Blynk.virtualWrite(V2, vIN1);
  Blynk.virtualWrite(V3, vIN2);
}

/*****Motor movement functions******/
void carForward(int speed) {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}

void carBackward(int speed) {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}

void carLeft(int speed) {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}

void carRight(int speed) {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}

void carStop(int speed) {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}
