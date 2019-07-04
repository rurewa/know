// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// RGB - светильник, управляемый последовательным соединением USB. Для Arduino Dev Board
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

const int BLED = 9;
const int GLED = 10;
const int RLED = 11;
int ledMode = 0;

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

void colourPurple() { // Пурпурный
  digitalWrite(BLED, HIGH);
  digitalWrite(GLED, LOW);
  digitalWrite(RLED, HIGH);
}

void colourTurquoise() { // Бирюзовый
  digitalWrite(BLED, HIGH);
  digitalWrite(GLED, HIGH);
  digitalWrite(RLED, LOW);
}

void colourOrange() { // Оранжевый
  digitalWrite(BLED, LOW);
  digitalWrite(GLED, HIGH);
  digitalWrite(RLED, HIGH);
}

void colourOff() { //  Выключить все цвета
  digitalWrite(BLED, LOW);
  digitalWrite(GLED, LOW);
  digitalWrite(RLED, LOW);
}

void setup() {
  pinMode(9, OUTPUT); // Настраиваем пины на Выход
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available() > 0) // Ожидаем ввод данных в монитор порт
  {
    ledMode = Serial.read(); // Записываем введённые данные

    switch (ledMode) // Сравниваем полученные данные с 1, 2, 3 и 6
    {
      case '1': // Если совпало с 1
        colourRed(); // Включаем красный
      break;  // Принудительный выход из оператора switch

      case '2': // Если совпало с 2
        colourGreen();  // Включаем зелёный
      break;  // Принудительный выход из оператора switch

      case '3': // Если совпало с 3
        colourBlue(); // Включаем голубой
      break;

      case '4':
        colourPurple(); // Включаем Пурпурный
      break;

      case '5':
        colourTurquoise(); // Включаем Бирюзовый
      break;

      case '6':
        colourOrange(); // Включаем Оранжевый
      break;

      default: //
        colourOff();
        Serial.println("------- MENU -------");
        Serial.println("1. Switch LED is Red");
        Serial.println("2. Switch LED is Green");
        Serial.println("3. Switch LED is Blue");
        Serial.println("4. Switch LED is Blue");
        Serial.println("5. Switch LED is Blue");
        Serial.println("6. Switch LED is Blue");
        Serial.println("=>7. This menu.");
        Serial.println("--------------------");
      break;  // Принудительный выход из оператора switch
    }
  }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //