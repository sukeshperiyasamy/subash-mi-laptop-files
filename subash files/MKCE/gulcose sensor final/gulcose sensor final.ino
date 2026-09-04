#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); // I2C address 0x27, 16 columns, 2 rows

const int analogPin = A0;
const float A = 8e-5;
const float B = 0.1873;
const float C = 46.131;

const int numReadings = 10;
int readings[numReadings];
int readIndex = 0;
long total = 0;

void setup() {
  Wire.begin();
  lcd.begin();  // Initialize the LCD
// Turn on the backlight
  Serial.begin(9600);
  pinMode(analogPin, INPUT); 
  for (int i = 0; i < numReadings; i++) {
    readings[i] = 0;
  }
}

void loop() {
  int rawValue = analogRead(analogPin);
  total -= readings[readIndex];
  readings[readIndex] = rawValue;
  total += rawValue;
  readIndex = (readIndex + 1) % numReadings;
  float averageVoltage = (float)total / numReadings * 5.0 / 1024.0; 

  float glucoseConcentration = A * pow(averageVoltage, 2) + B * averageVoltage + C;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Glucose:");
  lcd.setCursor(0, 1);
  lcd.print(glucoseConcentration, 1);
  lcd.print(" mg/dl");
  Serial.print("Glucose: ");
  Serial.print(glucoseConcentration, 1);
  Serial.println(" mg/dl");

  delay(1000); 
}
