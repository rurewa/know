// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// RGB - светильник, управляемый одной кнопкой c эффектом триггера. Для Arduino Dev Board
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
#include <Button_Simple.h>

const int BLED = 9;
const int GLED = 10;
const int RLED = 11;

int ledMode =  0; // Режимы для выбора цвета
// bool buttonState = 0; // Состояние кнопки (нажата/не нажата)

void colourRed();
void colourGreen();
void colourBlue();
void colourWhite();
void colourOff();

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool buttonState = digitalRead(13);
  if (buttonState == true) {
    // Счётчик увеличивает ledMode и обнуляет, когда значение достигает 3
    if (ledMode++ >= 3) { ledMode = 0; } // Счётчик и ограничитель
      switch (ledMode)
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
  Serial.println(ledMode); // Для диагностики
  }
}

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
  digitalWrite(BLED, HIGH);
  digitalWrite(GLED, HIGH);
  digitalWrite(RLED, HIGH);
}
void colourOff() { //  Выключить все цвета
  digitalWrite(BLED, LOW);
  digitalWrite(GLED, LOW);
  digitalWrite(RLED, LOW);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //