// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// RGB - светильник, управляемый одной кнопкой - триггером
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

const int BLED = 9;
const int GLED = 10;
const int RLED = 11;
const int BUTTON = 3;
int MODE_AM = 4; // Количество режимов
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
  if (buttonState == HIGH) // Если кнопка нажата
  // Увеличиваем ledMode, пока не выйдет за границы 4 (обнуляем)
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
  case 4:
    colourOff();
    break;
    break;
  default:
    break;
  }
  Serial.println(ledMode);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //