int EN = 9;
int IN1 = 2;
int IN2 = 4;

void setup()
{
  pinMode(EN,OUTPUT);
   pinMode(IN1,OUTPUT);
    pinMode(IN2,OUTPUT);

    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(EN,LOW);
}

void loop()
{
  digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(EN,255);
   delay(2000);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(EN,125);
    delay(2000);

    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(EN,LOW);
      delay(2000);
}

