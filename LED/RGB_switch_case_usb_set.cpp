// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// RGB - светильник, управляемый последовательным соединением USB. Для Arduino Dev Board
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

const int BLED = 9;
const int GLED = 10;
const int RLED = 11;
char ledMode = 0;

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

    switch (ledMode) // Сравниваем полученные данные с 1, 2, 3 и 4
    {
      case '1': // Если совпало с 1
        colourRed(); // Включаем красный
        Serial.println("LED is Red");  // Посылаем в монитор порта сообщение
      break;  // Принудительный выход из оператора switch

      case '2': // Если совпало с 2
        colourGreen();  // Включаем зелёный
        Serial.println("LED is Green"); // Посылаем сообщение в монитор порта
      break;  // Принудительный выход из оператора switch

      case '3': // Если совпало с 3
        colourBlue(); // Включаем голубой
        Serial.println("LED is Blue");
      break; // Принудительный выход из оператора switch

      case '4': // Если совпало с 3, посылаем сообщения в монитор порта
        Serial.println("------- MENU -------");
        Serial.println("1. Switch LED is Red");
        Serial.println("2. Switch LED is Green");
        Serial.println("3. Switch LED is Blue");
        Serial.println("4. This menu.");
        Serial.println("--------------------");
      break;  // Принудительный выход из оператора switch
    }
  }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //