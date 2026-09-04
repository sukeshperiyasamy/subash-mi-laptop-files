int Pirpin = 4;
int led = 13;
int PirState = 0;
void setup() {
  pinMode(Pirpin, INPUT);
  pinMode(led, OUTPUT);
}
void loop()
 {
  PirState = digitalRead(Pirpin);

  if (PirState == HIGH)
  {
    digitalWrite(13, HIGH);

  }

 else
  {
    digitalWrite(13, LOW);
  }
}
