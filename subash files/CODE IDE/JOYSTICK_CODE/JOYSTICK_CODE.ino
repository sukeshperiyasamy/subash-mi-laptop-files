
#include <Servo.h>
Servo myServo1;
Servo myServo2;
int servo1 = 3; 
int servo2 = 5; 
int joyX = 0;   
int joyY = 1;   

void setup(){
  myServo1.attach(servo1);
  myServo2.attach(servo2);
}

void loop(){
  int valX = analogRead(joyX); 
  int valY = analogRead(joyY); 
  valX = map(valX, 0, 1023, 10, 170); 
  valY = map(valY, 0, 1023, 10, 170); 
  myServo1.write(valX);   
  myServo2.write(valY);
  delay(5);
}
