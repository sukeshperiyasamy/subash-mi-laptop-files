void setup()
{
  pinMode(21,INPUT_PULLUP);
 pinMode(2,OUTPUT);
 Serial.begin(9600);
}
void loop(){
  int x=digitalRead(21);
  if(x==0)
  {
    digitalWrite(2,HIGH);
    Serial.println("ON");
  }
  else
  {
    digitalWrite(2,LOW);
    Serial.println("OFF");
  }
}
