#include <Arduino.h>
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// RGB - светильник, управляемый одной кнопкой - триггером
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
const int PIN_BLUE = 9;
const int PIN_GREEN = 10;
const int PIN_RED = 11;

const int PIN_BUTTON = 17;

void colorRed();
void colorGreen();
void colorBlue();
void colorWhite();
void colorPink();
void colorOff();
void colorYellow();

void setup() {
  pinMode(PIN_BLUE, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool buttonState = digitalRead(PIN_BUTTON);
  static int setMode = 4;
  static int ledMode = 0;
  if (buttonState == true) {
    if (++ledMode >= setMode) {
      ledMode = 0;
    }
    switch (ledMode)
    {
      case 1:
        colorRed();
        break;
      case 2:
        colorBlue();
        break;
      case 3:
        colorGreen();
        break;
      default:
        colorOff();
        break;
    }
  }
  Serial.println(ledMode);
}

void colorRed() {
  digitalWrite(PIN_BLUE, LOW);
  digitalWrite(PIN_RED, HIGH);
  digitalWrite(PIN_GREEN, LOW);
}

void colorGreen() {
  digitalWrite(PIN_BLUE, LOW);
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_GREEN, HIGH);
}

void colorBlue() {
  digitalWrite(PIN_BLUE, HIGH);
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_GREEN, LOW);
}

void colorWhite() {
  digitalWrite(PIN_BLUE, HIGH);
  digitalWrite(PIN_RED, HIGH);
  digitalWrite(PIN_GREEN, HIGH);
}

void colorOff() {
  digitalWrite(PIN_BLUE, LOW);
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_GREEN, LOW);
}

void colorPink() {
  digitalWrite(PIN_BLUE, HIGH);
  digitalWrite(PIN_RED, HIGH);
  digitalWrite(PIN_GREEN, LOW);
}

void colorYellow() {
  digitalWrite(PIN_BLUE, LOW);
  digitalWrite(PIN_RED, HIGH);
  digitalWrite(PIN_GREEN, HIGH);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
