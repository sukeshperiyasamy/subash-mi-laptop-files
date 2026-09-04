void setup() {
  // put your setup code here, to run once:
pinMode(8,INPUT);
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int buttonState= digitalRead(8);
if (buttonState == HIGH) {
digitalWrite(13,1);
}
else {
  digitalWrite(13,0);
}
}
