#include <SoftwareSerial.h>

// Define the RX and TX pins for the SIM900 module
SoftwareSerial sim900(7, 8);  // RX, TX

void setup() {
  // Open a serial connection with the Arduino's hardware serial port for debugging
  Serial.begin(9600);

  // Set the baud rate for the SIM900 module
  sim900.begin(9600);

  // Initialize the SIM900 module
  delay(1000);
  sim900.println("AT"); // Send AT command to check if module is responsive
  delay(1000);
  sim900.println("AT+CMGF=1"); // Set SMS mode to text mode
  delay(1000);

  // Answer an incoming call automatically
  sim900.println("ATA"); // Answer the call
}

void loop() {
  // Your main loop code goes here
}




