//Temperature sensor code:
#include <LiquidCrystal.h>    
 
LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7); 
  
void setup() { 
  
  analogReference(DEFAULT); 
  pinMode(A0, INPUT);  
  
  lcd.begin(16, 2);    
  
} 
  
void loop() { 
  
  int a ;   
  float   Temperature ;      
  
  a = analogRead(A0);  
   
  Temperature = (a / 2.054) ;  
  lcd.clear();   
  lcd.print("temperature: ");   
  lcd.print(Temperature);   
  lcd.print("C");   
  lcd.setCursor(2, 1);    
  lcd.print("maker creative");   
  delay(500);  
  
}