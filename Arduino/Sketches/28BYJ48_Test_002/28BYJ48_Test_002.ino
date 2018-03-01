int clockPin = 13;
int dirPin = 2;
int steps = 4096;
int dir = 1;

void step() {
  digitalWrite(clockPin, HIGH);
  delay(1);
  digitalWrite(clockPin, LOW);
  delay(1);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(clockPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dirPin, HIGH);
  for(int i=0; i < steps; i++) {
    step();
  }
  delay(1000);
  digitalWrite(dirPin, LOW);
  for(int i=0; i < steps; i++) {
    step();
  }
}
