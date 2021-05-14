#include "IRremote.h"

const int FORWARD = 0xFF9867;
const int BACKWARD = 0xFF38C7;
const int LEFT = 0xFF30CF;
const int RIGHT = 0xFF7A85;

IRrecv irrecv(17);

decode_results results;

int RightMotorSpeed = 155;
int LeftMotorSpeed = 155;

int RightMotorPin = 9;
int RightMotorIn1 = 7;
int RightMotorIn2 = 6;
int LeftMotorPin /*= 3;
int LeftMotorIn1 = 5;
int LeftMotorIn2 = 4;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  
  analogWrite (RightMotorPin, RightMotorSpeed);
  analogWrite (LeftMotorPin, LeftMotorSpeed);
  
  pinMode (RightMotorIn1, OUTPUT);
  pinMode (RightMotorIn2, OUTPUT);
  pinMode (LeftMotorIn1, OUTPUT);
  pinMode (LeftMotorIn2, OUTPUT);
}
void loop() { 
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    irrecv.resume(); 
  }
  /*if (irrecv.decode(&results))
  {
    switch (results.value) {
      case FORWARD: // - вперёд,
        digitalWrite (RightMotorIn1, LOW);
        digitalWrite (RightMotorIn2, HIGH);
        digitalWrite (LeftMotorIn1, LOW);
        digitalWrite (LeftMotorIn2, HIGH);
        break;
      case BACKWARD: // - назад,
        digitalWrite (RightMotorIn1, HIGH);
        digitalWrite (RightMotorIn2, LOW);
        digitalWrite (LeftMotorIn1, HIGH);
        digitalWrite (LeftMotorIn2, LOW);
        break;
      case LEFT: // - влево,
        digitalWrite (RightMotorIn1, HIGH);
        digitalWrite (RightMotorIn2, LOW);
        digitalWrite (LeftMotorIn1, LOW);
        digitalWrite (LeftMotorIn2, HIGH);
        break;
      case RIGHT: // - вправо
        digitalWrite (RightMotorIn1, LOW);
        digitalWrite (RightMotorIn2, HIGH);
        digitalWrite (LeftMotorIn1, HIGH);
        digitalWrite (LeftMotorIn2, LOW);
        break;
    }
  }*/
}
