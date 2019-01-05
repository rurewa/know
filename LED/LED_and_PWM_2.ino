#include <Arduino.h>

void foo(const int pot, int val){
  val = analogRead(pot) /4;
  analogWrite(10, val);
}

void setup(){
  pinMode(10, OUTPUT);
}

void loop(){
  foo(A0, 0);
}