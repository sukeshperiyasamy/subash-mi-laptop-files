void setup() {
    // Button input
  pinMode(11, OUTPUT);  
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT); // LED output
}

void loop() {
  digitalWrite(11, HIGH); 
  digitalWrite(12, LOW); 
    digitalWrite(13, LOW);  // Turn on LED
 delay(1000);
     digitalWrite(11, LOW); 
  digitalWrite(12, HIGH); 
    digitalWrite(13, LOW);  // Turn off LED
  delay(1000);
   digitalWrite(11, LOW); 
  digitalWrite(12, LOW); 
    digitalWrite(13, HIGH);  // Turn off LED
  delay(1000);

digitalWrite(11, LOW); 
  digitalWrite(12, LOW); 
    digitalWrite(13, LOW);  // Turn off LED
  delay(1500);
  
  digitalWrite(10, HIGH); 
  digitalWrite(9, LOW); 
    digitalWrite(8, LOW);  // Turn on LED
 delay(1000);
     digitalWrite(10, LOW); 
  digitalWrite(9, HIGH); 
    digitalWrite(8, LOW);  // Turn off LED
  delay(1000);
   digitalWrite(10, LOW); 
  digitalWrite(9, LOW); 
    digitalWrite(8, HIGH);  // Turn off LED
  delay(1000);

}
