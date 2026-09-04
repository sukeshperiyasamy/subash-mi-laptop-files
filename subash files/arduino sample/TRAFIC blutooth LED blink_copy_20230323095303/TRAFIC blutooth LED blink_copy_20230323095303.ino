void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
char in = (char)Serial.read();

if (in == 'A')
  {
    digitalWrite(13,HIGH);
    Serial.print(in);
  }
else if (in == 'AA')
  {
    digitalWrite(13,LOW);
    Serial.print(in);
  }  
if (in == 'B')
  {
    digitalWrite(12,HIGH);
    Serial.print(in);
  }
 else if (in == 'BB')
  {
    digitalWrite(12,LOW);
    Serial.print(in);
  }  
  if (in == 'C')
  {
    digitalWrite(11,HIGH);
    Serial.print(in);
  }
   else if (in == 'CC')
  {
    digitalWrite(11,LOW);
    Serial.print(in);
  }  
  
}
