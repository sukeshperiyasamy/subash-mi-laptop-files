#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

const int analogPin = A0;
const float A = 0.00008;
const float B = 0.1873;
const float C = 46.131;

const int numReadings = 10;
int readings[numReadings];
int readIndex = 0;
long total = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  
}

void loop() {
  int rawValue = analogRead(analogPin);
  float voltage = (float)rawValue * (5.0 / 1024.0);
  float x = voltage * 1000.0; //mV
  int  y = ((A * pow(x, 2) )+ B * x + C)*100;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Voltage:");
  lcd.setCursor(0, 1);
  lcd.print(x, 2);
  lcd.print(" mV");

  Serial.print("Voltage: ");
  Serial.print(x, 4); 
  Serial.println(" mV");

  Serial.print("Gulcose :");
  Serial.print(y, 4); 
  Serial.println(" mg/dl");

  delay(1000);
}
