// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Учебный пример использования массивов
// Accessing Array Elements
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

void setup() {
    Serial.begin(9600);
}

void loop() {
  const int ARRAY_LENGHT = 5; // Размер массива
  int myNumbers[ARRAY_LENGHT] = { -155, 3, 68, -20, 1 }; // Содержимое массива
  static int count = 1; // Счётчик
  while (count <= 1)
  {
     count++;
     Serial.print("Элемент массива 0: ");
     Serial.println(myNumbers[0]);
     Serial.print("Элемент массива 1: ");
     Serial.println(myNumbers[1]);
     Serial.print("Элемент массива 2: ");
     Serial.println(myNumbers[2]);
     Serial.print("Элемент массива 3: ");
     Serial.println(myNumbers[3]);
     Serial.print("Элемент массива 4: ");
     Serial.println(myNumbers[4]);
  }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //