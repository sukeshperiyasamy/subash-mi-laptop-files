#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11

DHT subash(DHTPIN,DHTTYPE);

void setup() 
{
  Serial.begin(115200);
  subash.begin();

}

void loop() 
{
  float h=subash.readHumidity();
  float t=subash.readTemperature();

  if(isnan(h) || isnan(t))
  {
  Serial.print("sensor faild");
  return;
  }

Serial.print("HUMIDITY :");
Serial.print(h);
Serial.print("%/t");
Serial.print("TEMPERTURE :");
Serial.print(t);
}
