// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// RGB - светильник, управляемый последовательным соединением USB. Для Arduino Dev Board
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

const int BLED = 9;
const int GLED = 10;
const int RLED = 11;

void colourRed() {
  digitalWrite(RLED, HIGH);
  digitalWrite(GLED, LOW);
  digitalWrite(BLED, LOW);
}

void colourGreen() {
  digitalWrite(RLED, LOW);
  digitalWrite(GLED, HIGH);
  digitalWrite(BLED, LOW);
}

void colourBlue() {
  digitalWrite(RLED, LOW);
  digitalWrite(GLED, LOW);
  digitalWrite(BLED, HIGH);
}

void colourOff() {
  digitalWrite(RLED, LOW);
  digitalWrite(GLED, LOW);
  digitalWrite(BLED, LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
    bool btn1 = false; bool btn2 = false; bool btn3 = false;
    int flag = 0;
    btn1 = digitalRead(13);
    btn2 = digitalRead(16);
    btn3 = digitalRead(17);
    if (btn1 == true) {flag = 1;}
    if (btn2 == true) {flag = 2;}
    if (btn3 == true) {flag = 3;}

    switch (flag)
    {
    case 1:
      colourRed();
      break;
    case 2:
      colourGreen();
    break;
    case 3:
      colourBlue();
    break;
    default:
      colourOff();
    break;
    }
    Serial.println(flag);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //