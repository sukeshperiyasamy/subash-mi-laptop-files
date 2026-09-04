#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// Define the motor pins

#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4

// Define the relay pins

// Variables for the Blynk widget values
int x = 50;
int y = 50;

#define BLYNK_TEMPLATE_ID "TMPL3pa_shCeh"
#define BLYNK_TEMPLATE_NAME "CH3"
#define BLYNK_AUTH_TOKEN "A9QGVrqCljpF5Vy_4kB39duDwQcTk9U4"
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "EVCAM";
char pass[] = "12345678";
void setup() {
Serial.begin(115200);

pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);


// Initialize the Blynk library
Blynk.begin(auth, ssid, pass, "blynk.cloud", 80); }
// Get the joystick values
BLYNK_WRITE(V0) { x = param[0].asInt(); }
// Get the joystick values
BLYNK_WRITE(V1) { y = param[0].asInt(); }
// Get the slider values

void smartcar() {

if (y > 70) {
carForward();
Serial.println("carForward");
} else if (y < 30) {
carBackward();
Serial.println("carBackward"); } else if (x < 30) {
carLeft();
Serial.println("carLeft"); } else if (x > 70) {
carRight();
Serial.println("carRight"); } else if (x < 70 && x > 30 && y < 70 && y > 30) {
carStop();
Serial.println("carstop"); } }
void loop() {
Blynk.run();
smartcar(); }
/**************Motor movement functions*****************/
void carForward() {

digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW); }
void carBackward() {

digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH); }
void carLeft() {

digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW); }
void carRight() {

digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH); }
void carStop() {
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW); }
