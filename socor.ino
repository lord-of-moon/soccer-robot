char value;

void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT); //  for Attack function
  Serial.begin(9600);
}

void forward() {
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}

void backward() {
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void right() {
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}

void left() {
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void Attack() {
  digitalWrite(8, HIGH);
  
}

void stops() {
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
 
}

void loop() {
  if (Serial.available() > 0) {
    value = Serial.read();
    Serial.println(value);
    
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
    if (value == 'A') {
      Attack();
    } 
    if (value == 'S') {
      stops();
    }
  }
}
