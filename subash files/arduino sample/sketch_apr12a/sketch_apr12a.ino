int buzzer=4;
void setup() {
// initialize the serial communication:
Serial.begin(9600);
pinMode(34, INPUT); // Setup for leads off detection LO +
pinMode(35, INPUT); // Setup for leads off detection LO -

pinMode(16, OUTPUT); // Setup for relay1
pinMode(17, OUTPUT); // Setup for relay2
pinMode(buzzer,OUTPUT);//setup for buzzer
 
}
 
void loop() {
 
if((digitalRead(34) == 1)||(digitalRead(35) == 1))
{
Serial.println('!');
digitalWrite(16,HIGH);
digitalWrite(17,HIGH);
digitalWrite(buzzer,HIGH);
delay(2000);
digitalWrite(16,LOW);
digitalWrite(17,LOW);
digitalWrite(buzzer,LOW);
delay(1000);
}
else{
// send the value of analog input 0:
Serial.println(analogRead(32));
}
//Wait for a bit to keep serial data from saturating
delay(1);
}