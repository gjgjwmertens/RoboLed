#include <OneWire.h>
#include <DallasTemperature.h>

#define STEPPER_001_CLOCK_PIN 13
#define STEPPER_001_DIR_PIN   4
#define CW                    HIGH
#define CCW                   LOW
#define STEPPER_001_STEPS     1000
#define FAN_001_PWM_PIN       3
#define FAN_001_TACHO_PIN     2
#define TEMP_001_DATA_PIN     7
#define LED_001_PWM_PIN       11

OneWire oneWire(TEMP_001_DATA_PIN);
DallasTemperature sensors(&oneWire);

void step() {
  // The step occurs on the rising edge of the signal (L297)
  digitalWrite(STEPPER_001_CLOCK_PIN, HIGH);
  delay(1);
  digitalWrite(STEPPER_001_CLOCK_PIN, LOW);
  delay(1);
}

void turn(bool dir) {
  digitalWrite(STEPPER_001_DIR_PIN, dir);
  for(int i=0; i < STEPPER_001_STEPS; i++) {
    step();
//    delay(5);              
  }
}

void setup() {
  Serial.begin(9600);
  // set PWM frequency pin 11 and 3
  // 0x01 = 31kHz
  // this setting is reset with every upload
  TCCR2B = TCCR2B & 0b11111000 | 0x01;
  // timer 0 infuences the overall timing??
//  TCCR0B = TCCR0B & 0b11111000 | 0x03;
  // put your setup code here, to run once:
  pinMode(STEPPER_001_CLOCK_PIN, OUTPUT);
  pinMode(STEPPER_001_DIR_PIN, OUTPUT);
  pinMode(FAN_001_PWM_PIN, OUTPUT);
  pinMode(TEMP_001_DATA_PIN, INPUT_PULLUP);
  pinMode(LED_001_PWM_PIN, OUTPUT);

  sensors.begin();
  analogWrite(FAN_001_PWM_PIN, 25);
  analogWrite(LED_001_PWM_PIN, 255);
}

void loop() {
  // put your main code here, to run repeatedly:
  turn(CW);
  delay(500);
  turn(CCW);
//  Serial.println("Requesting temp...");
  sensors.requestTemperatures();
//  Serial.println("Done");
  Serial.print("Temperature is: ");
  Serial.println(sensors.getTempCByIndex(0));
  delay(1000);
//  turn(LOW);
}
