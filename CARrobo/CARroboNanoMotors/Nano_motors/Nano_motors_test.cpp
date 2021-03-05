// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Тестовая программа управления драйвером мотора на плате NanoMotors Junior
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
// Управление левым мотором
const int ENA = 10;
const int in2 = 12;
// Управление правым мотором
const int ENB = 9;
const int in3 = 11;

void leftMotor(int SPEED);
void rightMotor(int SPEED);
void stopMotor(int TIME);

const int SPEED = 155; // Скорость моторов в ШИМ

void setup() {
    // Настройка левого мотора
    pinMode(in2, OUTPUT);
    pinMode(ENA, OUTPUT);
    // Настройка правого мотора
    pinMode(ENB, OUTPUT);
    pinMode(in3, OUTPUT);
}

void loop() {
    leftMotor(SPEED);
    delay(2000);
    stopMotor(1000);
    rightMotor(SPEED);
    delay(2000);
    stopMotor(1000);
}
void leftMotor(int SPEED) {
    digitalWrite(in2, LOW);
    analogWrite(ENA, SPEED);
    digitalWrite(in3, LOW);
    analogWrite(ENB, SPEED);
}

void rightMotor(int SPEED) {
    digitalWrite(in2, HIGH);
    analogWrite(ENA, SPEED);
    digitalWrite(in3, HIGH);
    analogWrite(ENB, SPEED);
}

void stopMotor(int TIME) {
    analogWrite(ENB, 0);
    analogWrite(ENA, 0);
    delay(TIME);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
