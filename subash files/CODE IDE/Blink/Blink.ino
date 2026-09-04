
void setup() {                
 
  pinMode(2, OUTPUT);   
  pinMode(14,OUTPUT);
}
void loop() {
  digitalWrite(2, HIGH); 
   digitalWrite(14, HIGH);
  delay(1000);               
  digitalWrite(2, LOW); 
  digitalWrite(14, LOW);
  delay(1000);              
               
}
