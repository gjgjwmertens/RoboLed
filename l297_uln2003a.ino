

int STEP = 2;
int DIR = 3;
int EN = 4;



int mSpeed = 10;


void setup(){
  
  pinMode(STEP,OUTPUT);
  pinMode(DIR,OUTPUT);
  pinMode(EN,OUTPUT);
  
  
  
  digitalWrite(EN,HIGH);
  digitalWrite(DIR,HIGH);
  
}


void loop(){
  
  digitalWrite(STEP,HIGH);
  delay(mSpeed);
  digitalWrite(STEP,LOW);
  delay(mSpeed);
  
}
