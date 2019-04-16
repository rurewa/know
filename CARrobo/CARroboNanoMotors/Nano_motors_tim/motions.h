// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Библиотека управления драйвером мотора робота движения по линии от Тимофея
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

const int ENA = 10;
const int ENB = 9;
const int MotorLeft = 11;
const int MotorRight = 12;
const int SensorLeft =8;
const int SensorRight = 6;
const int SensorMiddle = 7;

void forward()
{
    digitalWrite(MotorLeft, HIGH);
    digitalWrite(MotorRight, HIGH);
}
void left()
{
    digitalWrite(MotorLeft, LOW);
    digitalWrite(MotorRight, HIGH);
}
void right()
{
    digitalWrite(MotorLeft, HIGH);
    digitalWrite(MotorRight, LOW);
}
void forward_left()
{
    forward();
    delay(200);
    left();
    delay(200);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //