// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// RGB - светильник, управляемый одной кнопкой - триггером
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

const int BLED = 9;
const int GLED = 10;
const int RLED = 11;
const int BUTTON = 3;
int  ledMode =  0; // Режимы для выбора цвета
int buttonState = 0; // Состояние кнопки (нажата/не нажата)

void colourRed() { // Красный
  digitalWrite(BLED, LOW);
  digitalWrite(GLED, LOW);
  digitalWrite(RLED, HIGH);
}

void colourGreen() { // Зелёный
  digitalWrite(BLED, LOW);
  digitalWrite(GLED, HIGH);
  digitalWrite(RLED, LOW);
}

void colourBlue() { // Голубой
  digitalWrite(BLED, HIGH);
  digitalWrite(GLED, LOW);
  digitalWrite(RLED, LOW);
}

void colourWhite() { // Белый
  digitalWrite(BLED, LOW);
  digitalWrite(GLED, LOW);
  digitalWrite(RLED, LOW);
}
void colourOff() { //  Выключить все цвета
  digitalWrite(BLED, HIGH);
  digitalWrite(GLED, HIGH);
  digitalWrite(RLED, HIGH);
}

void setup() {
  for (int ledPin=9; ledPin<=11; ledPin++) {
    pinMode(ledPin, OUTPUT);
  }
  for (int leds=9; leds<=11; leds++) {
    digitalWrite(leds, HIGH);
  }
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(BUTTON);
  if (buttonState == HIGH) {
    ledMode++;
  }
  if (ledMode == 0) {
    colourRed();
  }
  else if (ledMode == 1) {
    colourGreen();
  }
  else if (ledMode == 2) {
    colourBlue();
  }
  else if (ledMode == 3) {
    colourWhite();
  }
  else if (ledMode == 4) {
    colourOff();
  }
  else if (ledMode == 5) {
    ledMode = 0;
  }
  Serial.println(ledMode);
  delay(60);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //