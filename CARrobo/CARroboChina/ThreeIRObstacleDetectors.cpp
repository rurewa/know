// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Движение по лабиринту с помощью 3-х IR датчиков препятствия
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

const int E1 = 10;      // Motor A1 PWM
const int M1 =  12;     // Motor A2 (left motor)
const int E2 =  11;     // Motor B1 PWM
const int M2 =  13;     // Motor B2 (right motor)

int SPEED = 125;  // Speed PWM 0 - 255

// Временные константы служат для точного задания времени на поворот, разворот, движение вперёд
// в миллисекундах.
/*const int time_90 = 190;
const int time_10 = 20;
const int time_180 = 380;
const int time_10cm = 100;*/

// Номера портов, к которым подключены датчики препятствия.
const int  Left = 17, Middle = 18, Right = 19;

void go() { // Вперёд
  digitalWrite(M1, LOW);
  analogWrite(E1, SPEED);
  digitalWrite(M2, LOW);
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

/*void backWard() {
  digitalWrite(M1, HIGH);
  analogWrite(E1, SPEED);
  digitalWrite(M2, HIGH);
  analogWrite(E2, SPEED);
}*/

void avtoroute() {  // Поведение
  do {
    bool d_Left, d_Middle, d_Right;
    d_Left = digitalRead(Left); d_Middle = digitalRead(Middle); d_Right = digitalRead(Right);
    if((d_Left) && (d_Middle) && (!d_Right)) { turnLeft(); Serial.println("LEFT: "); } // Если R сработал - влево!
    else if((!d_Left) && (d_Middle) && (d_Right)) { turnRight(); Serial.println("RIGHT: "); } // Если L сработал - вправо!
    else if((d_Left) && (!d_Middle) && (d_Right)) { turnLeft(); Serial.println("LEFT: "); } // Если M сработал - влево!
    else if((!d_Left) && (d_Middle) && (!d_Right)) { go(); Serial.println("FOWARD: "); } // Если M не сработал - вперёд!
    else if((!d_Left) && (!d_Middle) && (d_Right)) { turnRight(); Serial.println("RIGHT: "); } // Если L и M сработали - вправо!
    else if((d_Left) && (!d_Middle) && (!d_Right)) { turnLeft(); Serial.println("LEFT: "); } // Если M и R сработали - влево!
    else if((!d_Left) && (!d_Middle) && (!d_Right)) { turnRight(); Serial.println("RIGHT: "); } // Если все сработали - вправо!
    else { go(); Serial.println("FOWARD: ");} // Если все не сработали - вперёд!
    delay(150);
  }
  while(true);
}

void setup() {
  Serial.begin(9600);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
}
// Основная программа.
void loop() {
  avtoroute(); // Поведение
  // Код проверки датчиков
  /*bool d_Left, d_Middle, d_Right;
  d_Left = digitalRead(Left); d_Middle = digitalRead(Middle); d_Right = digitalRead(Right);
  Serial.print("Left: ");
  Serial.print(d_Left);
  Serial.print(" Middle: ");
  Serial.print(d_Middle);
  Serial.print(" Right: ");
  Serial.println(d_Right);*/
  //delay(50);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //