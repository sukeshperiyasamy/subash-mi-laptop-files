void setup()
{
  pinMode(21,INPUT_PULLUP);
 pinMode(2,OUTPUT);
}
void loop(){
  int x=digitalRead(21);
  if(x==0)
  {
    digitalWrite(2,HIGH);
  }
  else
  {
    digitalWrite(2,LOW);
  }
}
