#include "IRremote.h"

int walk = 0;

IRrecv irrecv(A3);
decode_results results;

const int RightMotorSpeed = 255;
const int LeftMotorSpeed = 255;

const int RightMotorPin = 9;
const int RightMotorIn1 = 7;
const int RightMotorIn2 = 6;
const int LeftMotorPin = 3;
const int LeftMotorIn1 = 5;
const int LeftMotorIn2 = 4;

unsigned long timer = 0;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode (RightMotorIn1, OUTPUT);
  pinMode (RightMotorIn2, OUTPUT);
  pinMode (LeftMotorIn1, OUTPUT);
  pinMode (LeftMotorIn2, OUTPUT);
}
void loop() { 
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    switch (results.value) {
      case 0xFF9867: // - вперёд,
        forward ();
        walk = 1;
        break;
      case 0xFF38C7: // - назад,
        backward ();
        walk = 2;
        break;
      case 0xFF30CF: // - влево,
        left ();
        walk = 3;
        break;
      case 0xFF7A85: // - вправо
        right ();
        walk = 4;
        break;
      case 0xFFFFFFFF: // - повтор последней команды
        if (walk == 1) {
          forward ();
        }
        if (walk == 2) {
          backward ();
        }
        if (walk == 3) {
          left ();
        }
        if (walk == 4) {
          right ();
        }
        break;
    }
    irrecv.resume();
  }
  delay (100);
  digitalWrite (RightMotorIn1, LOW);
  digitalWrite (RightMotorIn2, LOW);
  digitalWrite (LeftMotorIn1, LOW);
  digitalWrite (LeftMotorIn2, LOW);
  analogWrite (RightMotorPin, 0);
  analogWrite (LeftMotorPin, 0);
}


void forward () {
  analogWrite (RightMotorPin, RightMotorSpeed);
  analogWrite (LeftMotorPin, LeftMotorSpeed);
  digitalWrite (RightMotorIn1, LOW);
  digitalWrite (RightMotorIn2, HIGH);
  digitalWrite (LeftMotorIn1, LOW);
  digitalWrite (LeftMotorIn2, HIGH);
}

void backward () {
  analogWrite (RightMotorPin, RightMotorSpeed);
  analogWrite (LeftMotorPin, LeftMotorSpeed);
  digitalWrite (RightMotorIn1, HIGH);
  digitalWrite (RightMotorIn2, LOW);
  digitalWrite (LeftMotorIn1, HIGH);
  digitalWrite (LeftMotorIn2, LOW);
}

void left () {
  analogWrite (RightMotorPin, RightMotorSpeed);
  analogWrite (LeftMotorPin, LeftMotorSpeed);
  digitalWrite (RightMotorIn1, HIGH);
  digitalWrite (RightMotorIn2, LOW);
  digitalWrite (LeftMotorIn1, LOW);
  digitalWrite (LeftMotorIn2, HIGH);
}

void right () {
  analogWrite (RightMotorPin, RightMotorSpeed);
  analogWrite (LeftMotorPin, LeftMotorSpeed);
  digitalWrite (RightMotorIn1, LOW);
  digitalWrite (RightMotorIn2, HIGH);
  digitalWrite (LeftMotorIn1, HIGH);
  digitalWrite (LeftMotorIn2, LOW);
}
