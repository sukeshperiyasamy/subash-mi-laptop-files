int trigPin = 2;
 int echoPin = 4;
int lightPin = 7;
long duration;
float distance;

void setup (){
  Serial.begin(9600);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
  pinMode(lightPin,OUTPUT);
}
void loop()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
 delayMicroseconds(10);
  // digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  Serial.print("Distance:");
  Serial.print(distance);
  Serial.println("Cm");
  if(distance>50)
  {
    digitalWrite(lightPin,LOW);
  }
  else
  {
    digitalWrite(lightPin,HIGH);
  }
}
