// scientist BENIEL'S LAB
// GAS DETECTOR

int Input = A0;
int R_LED = 2;
int G_LED = 3;
int Buzzer = 4;
// VAL INTEGER
int val;
int MAX = 400;

void setup() {
  Serial.begin(9600);
   Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
  pinMode(Input ,INPUT);
  pinMode(R_LED ,OUTPUT);
  pinMode(G_LED ,OUTPUT);
  pinMode(Buzzer ,OUTPUT);
}

void loop() {
  val = analogRead(A0);
  if (val >= MAX) {
    digitalWrite(R_LED ,HIGH);
    digitalWrite(Buzzer ,HIGH);
    digitalWrite(G_LED ,LOW);
    Serial.println("GAS LEAKING");
  }
  else {
    Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+919042249014\"\r");// Replace x with mobile number
  delay(1000);
  Serial.println(" sample ku unoda number potu test panra atha unku message varthu . ");// The SMS text you want to send
  delay(100);
  Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);

   while(1);  //Wait forever
    digitalWrite(R_LED ,LOW);
    digitalWrite(Buzzer ,LOW);
    digitalWrite(G_LED ,HIGH);
    Serial.println("NORMAL");
  }
}
