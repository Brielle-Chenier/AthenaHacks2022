#define step_pin1 10
#define step_pin2 11
#define step_pin3 12
#define step_pin4 13
#define comm_pin 7
#define comm_pin2 4
int step_num = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(step_pin1, OUTPUT);
  pinMode(step_pin2, OUTPUT);
  pinMode(step_pin3, OUTPUT);
  pinMode(step_pin4, OUTPUT);
  digitalWrite(step_pin1,LOW);
  digitalWrite(step_pin2,LOW);
  digitalWrite(step_pin3,LOW);
  digitalWrite(step_pin4,LOW);
  pinMode(comm_pin, INPUT);
  pinMode(comm_pin2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(comm_pin);
  if(val){ 
    delay(20);
    stepRight(6200);
  }
  val = digitalRead(comm_pin2);
  if(val){
    delay(20);
    stepLeft(6200);
  }
}

void stepRight(int step_number) {
  while(step_number>=0){
    switch(step_number%4){
      case 0:
      digitalWrite(step_pin1,HIGH);
      digitalWrite(step_pin2, LOW);
      digitalWrite(step_pin3,LOW);
      digitalWrite(step_pin4, LOW);
      break;
      case 1:
      digitalWrite(step_pin1,LOW);
      digitalWrite(step_pin2, HIGH);
      digitalWrite(step_pin3,LOW);
      digitalWrite(step_pin4, LOW);
      break;
      case 2:
      digitalWrite(step_pin1,LOW);
      digitalWrite(step_pin2, LOW);
      digitalWrite(step_pin3,HIGH);
      digitalWrite(step_pin4, LOW);
      break;
      case 3:
      digitalWrite(step_pin1,LOW);
      digitalWrite(step_pin2, LOW);
      digitalWrite(step_pin3,LOW);
      digitalWrite(step_pin4, HIGH);
      break;
    }
    step_number = step_number - 1;
    
    delay(2);
  }
}

void stepLeft(int step_number) {
  while(step_number>=0){
    switch(step_number%4){
      case 0:
      digitalWrite(step_pin1,LOW);
      digitalWrite(step_pin2, LOW);
      digitalWrite(step_pin3,LOW);
      digitalWrite(step_pin4, HIGH);
      break;
      case 1:
      digitalWrite(step_pin1,LOW);
      digitalWrite(step_pin2, LOW);
      digitalWrite(step_pin3,HIGH);
      digitalWrite(step_pin4, LOW);
      break;
      case 2:
      digitalWrite(step_pin1,LOW);
      digitalWrite(step_pin2, HIGH);
      digitalWrite(step_pin3,LOW);
      digitalWrite(step_pin4, LOW);
      break;
      case 3:
      digitalWrite(step_pin1,HIGH);
      digitalWrite(step_pin2, LOW);
      digitalWrite(step_pin3,LOW);
      digitalWrite(step_pin4, LOW);      
      break;
    }
    step_number = step_number - 1;
    delay(2);
  }
}
