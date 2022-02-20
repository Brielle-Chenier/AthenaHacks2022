#include <Servo.h>
Servo servo1;

int servoPin = 9;
int touchPin = 8;
int count  = 0;
#define step_pin1 10
#define step_pin2 11
#define step_pin3 12
#define step_pin4 13
#define comm_pin 7
#define comm_pin2 4
int step_num = 0;
int initial = 20;

#include <FastLED.h>
//#include <PS2Keyboard.h>
#define LED_PIN 2
#define NUM_LED 36
#define CAP = 3
//#define DATA_PIN 8
//#define IRQ_PIN 5
#define ARRAY_SIZE(A) (sizeof(A)/sizeof((A)[0]))
CRGB leds[NUM_LED];

void setup() {
  // put your setup code here, to run once:
  servo1.attach(servoPin);
  servo1.write(initial);
  pinMode(touchPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(step_pin1, OUTPUT);
  pinMode(step_pin2, OUTPUT);
  pinMode(step_pin3, OUTPUT);
  pinMode(step_pin4, OUTPUT);
  digitalWrite(step_pin1,LOW);
  digitalWrite(step_pin2,LOW);
  digitalWrite(step_pin3,LOW);
  digitalWrite(step_pin4,LOW);
  pinMode(comm_pin, OUTPUT);
  digitalWrite(comm_pin,LOW);
  pinMode(comm_pin2, OUTPUT);
  digitalWrite(comm_pin2,LOW);
  delay(1000);
  FastLED.addLeds<WS2812B, LED_PIN, RGB>(leds, NUM_LED);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  done();
  FastLED.show();
  
}

typedef void (*SimplePatternList[])();
SimplePatternList PATTERNS = {painting, done};
int state = 0;
int chargeState = 0;

void loop() {
  // put your main code here, to run repeatedly:
  //7 degree dif
  //int brush = 10;
  
  if(digitalRead(touchPin) == HIGH and count == 0) {
    painting();
    servo1.write(10);
    delay(1000);
    servo1.write(10 + 10);
    delay(1000);
    servo1.write(initial);
    delay(100);
    digitalWrite(comm_pin, HIGH);
    delay(20);
    digitalWrite(comm_pin, LOW);
    stepRight(6200);
    count = 1;
    servo1.write(initial+25);
    delay(1000);
    servo1.write(initial - 15);
    delay(2000);
    servo1.write(initial+25);
    delay(1000);
    digitalWrite(comm_pin2, HIGH);
    delay(20);
    digitalWrite(comm_pin2, LOW);
    done();
    stepLeft(6200);
    
  }

  if(digitalRead(touchPin) == LOW)  {
    count = 0;
    servo1.write(initial);
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

void painting ()
{
    for (int i = 0; i < NUM_LED; i++){
      leds[i]= CRGB(0,255,0);
    }
    FastLED.show();
}


void done ()
{
    for (int i = 0; i < NUM_LED; i++){
          leds[i]= CRGB(255,0,0);
    }
    FastLED.show();

}
