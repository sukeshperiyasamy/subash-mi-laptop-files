#include <Servo.h>
Servo myServo;
Servo myServoo;
int pos = 0;
int data;
void setup() {
  Serial.begin(9600);
  myServo.attach(9);
  myServoo.attach(10);
}
void loop() {

  if (Serial.available()) {

    data = Serial.read();

    if (data == 'A') {

      for (pos = 90; pos <= 180; pos += 1) {
        myServo.write(pos);
        delay(2);
      }
    }
    if (data == 'B') {
      for (pos = 90; pos >= 30; pos == 1) {
        myServo.write(pos);
        delay(2);
      }
    }
    if (data == 'Z') {
      for (pos = 0; pos <= 0; pos += 1) {
        myServo.write(pos);
        delay(2);
      }
    }
    if (data == 'C') {
      for (pos = 90; pos <= 180; pos += 1) {
        myServoo.write(pos);
        delay(2);
      }
    }
    if (data == 'D') {
      for (pos = 90; pos >= 30; pos == 1) {
        myServoo.write(pos);
        delay(2);
      }
    }
    if (data == 'z') {
      for (pos = 0; pos <= 0; pos += 1) {
        myServoo.write(pos);
        delay(2);
      }
    }
  }
}
