// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Робот с использованием L298P Motor Shield от Keyes управляемый Bluetooth
// и смартфоном
// Код приёмника
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

const int E1 = 10;      // Motor A1 PWM
const int M1 =  12;     // Motor A2 (left motor)
const int E2 =  11;     // Motor B1 PWM
const int M2 =  13;     // Motor B2 (right motor)

int SPEED = 155;  // Speed PWM 0 - 255

/*const int ledR = 3;
const int ledG = 5;
const int ledB = 6;*/

void go() { // Вперёд
  digitalWrite(M1, LOW);
  analogWrite(E1, SPEED);
  digitalWrite(M2, LOW);
  analogWrite(E2, SPEED);
}

void back() { // Назад
  digitalWrite(M1, HIGH);
  analogWrite(E1, SPEED);
  digitalWrite(M2, HIGH);
  analogWrite(E2, SPEED);
}

void turnLeft() { // Влево
  digitalWrite(M1, HIGH);
  analogWrite(E1, SPEED);
  digitalWrite(M2, LOW);
  analogWrite(E2, SPEED);
}

void turnRight() { // Вправо
  digitalWrite(M1, LOW);
  analogWrite(E1, SPEED);
  digitalWrite(M2, HIGH);
  analogWrite(E2, SPEED);
}

void stop() { // Стоп
  analogWrite(E1, 0);
  analogWrite(E2, 0);
}

void hornOn() { // Сигнал включён
  digitalWrite(4, HIGH);
}

void hornOff() { // Сигнал выключен
  digitalWrite(4, LOW);
}

void EyesOn() { // Глаза включены
  digitalWrite(3, HIGH);
}

void EyesOff() { // Глаза выключены
  digitalWrite(3, LOW);
}

void setup() {
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char data = 0;
  if(Serial.available() > 0) {
    data = (char)Serial.read();
    delay(10);
    Serial.print(data);
    Serial.print("\n");
    switch (data)
    {
      case 'F': // Вперёд
        go();
        break;
      case 'B': // Назад
        back();
        break;
      case 'S': // Стоп
        stop();
        break;
      case 'L': // Влево
        turnLeft();
        break;
      case 'R': // Вправо
        turnRight();
        break;
      case 'W': // Глаза включены
        EyesOn();
        break;
      case 'w': // Глаза выключены
        EyesOff();
        break;
      case 'V':
        hornOn();
        break;
      case 'v':
        hornOff()    ;
        break;
      default:
        break;
    }
  }
}