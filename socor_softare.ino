#include <SoftwareSerial.h>

SoftwareSerial BT(11, 10); // RX, TX (for Bluetooth module)

char value;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  // pinMode(12, OUTPUT); // For Attack function
  
  Serial.begin(9600); // Serial Monitor
  BT.begin(9600);     // Bluetooth communication

  Serial.println("Bluetooth Ready!");
}

void forward() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void backward() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}

void right() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void left() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}

// void Attack() {
//   digitalWrite(12, HIGH);
// }

void stops() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(12, LOW);
}

void loop() {
  if (BT.available()) { // Read from Bluetooth module
    value = BT.read();
    Serial.println(value); // Print received command
    
    if (value == 'F') {
      forward();
    } 
    if (value == 'B') {
      backward();
    } 
    if (value == 'R') {
      right();
    } 
    if (value == 'L') {
      left();
    } 
    // if (value == 'A') {
    //   Attack();
    } 
    if (value == 'S') {
      stops();
    }
  }
// }
