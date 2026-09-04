#include <SoftwareSerial.h>
SoftwareSerial Gsm(2, 3);
void setup()
{
  Serial.begin(9600);
  Gsm.begin(9600);
}

void loop()
{ 
  if (Gsm.available())
  {
    Serial.write(Gsm.read());;
  }
  if (Serial.available())
  {
    Gsm.write(Serial.read());
  }

}
