// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// RGB - светильник, управляемый одной кнопкой-триггером. Для Arduino Dev Board
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
#include <Button_Simple.h>

const int BLED = 9;
const int GLED = 10;
const int RLED = 11;
const int BUTTON = 13;
const int MODE_AM = 4; // Количество режимов (0..4)
int ledMode =  0; // Режимы для выбора цвета
bool buttonState = 0; // Состояние кнопки (нажата/не нажата)

Button_Simple button(13);

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
  digitalWrite(BLED, LOW);
  digitalWrite(GLED, LOW);
  digitalWrite(RLED, LOW);
}

void setup() {
  for (int ledPin=8; ledPin<=12; ledPin++) {
    pinMode(ledPin, OUTPUT); // Настраиваем пины на Выход
  }
  for (int leds=9; leds<=12; leds++) {
    digitalWrite(leds, LOW); // Выключем светодиоды
  }
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(BUTTON);
  if (buttonState == true) // Если кнопка нажата
  // Счётчик увеличивает ledMode и обнуляет, когда значение достигает 3
  if (++ledMode >= MODE_AM) ledMode = 0;
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
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //