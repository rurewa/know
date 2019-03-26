// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Black line movement for China car. biathlon
// V 2.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

const int E1 = 10;      // Motor A1 PWM
const int M1 =  12;     // Motor A2 (left motor)
const int E2 =  11;     // Motor B1 PWM
const int M2 =  13;     // Motor B2 (right motor)

int SPEED = 125;  // Speed PWM 0 - 255

const int SensorLeft = 14;
const int SensorMiddle= 15;
const int SensorRight = 16;

int diy = 100; // чтобы не дёргался на одном месте

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

void turnGoRight() { // Стоп и назад
  analogWrite(E1, 0);
  analogWrite(E2, 0);
  delay(diy);
  digitalWrite(M1, HIGH);
  analogWrite(E1, SPEED);
  digitalWrite(M2, HIGH);
  analogWrite(E2, SPEED);
  delay(diy);
}

void setup() {
  Serial.begin(9600);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
}

void loop() {
  do {
    bool SLeft = !digitalRead(SensorLeft); // Левый датчик
    bool SMiddle = !digitalRead(SensorMiddle); // Средний датчик
    bool SRight = !digitalRead(SensorRight); // Правый датчик
    if((SLeft) && (SMiddle) && (!SRight)) { go(); Serial.println("FOWARD: "); } // Если R на белом - влево!
    else if((!SLeft) && (SMiddle) && (SRight)) { go(); Serial.println("FOWARD: "); } // Если L на белом - вправо!
    else if((SLeft) && (!SMiddle) && (SRight)) { go(); Serial.println("FOWARD: "); } // Если M на белом - вперёд!
    else if((!SLeft) && (SMiddle) && (!SRight)) { go(); Serial.println("FOWARD: "); } // Если M на белом - вперёд!
    else if((!SLeft) && (!SMiddle) && (SRight)) { turnRight(); Serial.println("RIGHT: "); } // Если L и M на белом - вправо!
    else if((SLeft) && (!SMiddle) && (!SRight)) { turnLeft(); Serial.println("LEFT: "); } // Если M и R на белом - влево!
    else if((!SLeft) && (!SMiddle) && (!SRight)) { turnGoRight(); Serial.println("FOWARD & LEFT: "); } // Если все на белом - вперёд и влево!
    else { go(); Serial.println("FOWARD: ");} // Если все на чёрном - вперёд!
    delay(150);
  }
  while(true);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //