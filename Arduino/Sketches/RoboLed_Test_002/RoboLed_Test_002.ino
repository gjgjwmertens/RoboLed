int clockPin = 13;
int dirPin = 4;
int steps = 4096;
int dir = 1;
int fanPwmPin = 3;
int fanTacho = 2;

void step() {
  digitalWrite(clockPin, HIGH);
  delay(5);
  digitalWrite(clockPin, LOW);
  delay(5);
}

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(clockPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(fanPwmPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pwm = 100;
  analogWrite(fanPwmPin, pwm);
  digitalWrite(dirPin, HIGH);
  for(int i=0; i < steps; i++) {
//    pwm = int(i / 16);
//    Serial.println(pwm, DEC);
//    analogWrite(fanPwmPin, pwm);
    step();
  }
  delay(1000);
  digitalWrite(dirPin, LOW);
  for(int i=0; i < steps; i++) {
//    pwm = int((4096 - i) / 16);
//    Serial.println(pwm, DEC);
//    analogWrite(fanPwmPin, pwm);
    step();
  }
}
