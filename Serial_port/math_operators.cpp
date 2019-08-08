// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Пример выполнения основных математических операций
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

void setup() {
  Serial.begin(9600); // Инициализируем монитор порта
}

void loop() {
  int num1 = 20; // Объявляем переменную со значением 20
  int num2 = 15; // Объявляем переменную со значением 15
  static int count = 0;

  while (count <= 1) {
    ++count;

    Serial.print(num1); // Выводим на экран первое число
    Serial.print(" + "); // Выводим на экран знак операции
    Serial.print(num2); // Выводим на экран второе число
    Serial.print(" = "); // Выводим на экран знак операции
    Serial.println(num1 + num2); // Выводим на экран результат операции

    Serial.print(num1);
    Serial.print(" - ");
    Serial.print(num2);
    Serial.print(" = ");
    Serial.println(num1 - num2);

    Serial.print(num1);
    Serial.print(" * ");
    Serial.print(num2);
    Serial.print(" = ");
    Serial.println(num1 * num2);

    Serial.print(num1);
    Serial.print(" / ");
    Serial.print(num2);
    Serial.print(" = ");
    Serial.println(num1 / num2);

    Serial.print(num1);
    Serial.print(" % ");
    Serial.print(num2);
    Serial.print(" = ");
    Serial.println(num1 % num2); // Выводим на экран остаток деления
  }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
