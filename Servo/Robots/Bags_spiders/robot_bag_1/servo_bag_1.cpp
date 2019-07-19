#include <Arduino.h>
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Робот жук с двумя сервориводами SG90
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Servo.h>

Servo myServo1;
Servo myServo2;

void setup() {
  myServo1.attach(3); // Передний сервопривод
  myServo2.attach(10); // Задний сервопривод
}

void loop() {
  myServo1.write(90); // Передний сервопривод
  myServo2.write(80); // Задний сервопривод
  delay(250);
  myServo1.write(110);
  myServo2.write(120);
  delay(250);
}