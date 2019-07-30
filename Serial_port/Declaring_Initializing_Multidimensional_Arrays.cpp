// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Учебный пример извлечения данных из многомерного массива
// Declaring Initializing multidimensional Arrays
//
//      0    1     2
// 0 [-501][206] [2016]
// 1 [989] [101] [206]
// 2 [303] [456] [596]
//
//
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

int myNumbers[3] [3] =
{{ -501, 206, 2016 }, { 989, 101, 206}, { 303, 456, 596 }} ; // Содержимое многомерного массива

void setup() {
    Serial.begin(9600);
}

void loop() {
  static int count = 0;
  while (count < 1) {
    ++count;
    Serial.print("Строка 0, элемент 0: ");
    Serial.println(myNumbers[0][0]);
    Serial.print("Строка 0, элемент 1: ");
    Serial.println(myNumbers[0][1]);
    Serial.print("Строка 0, элемент 2: ");
    Serial.println(myNumbers[0][2]);

    Serial.print("Строка 1, элемент 0: ");
    Serial.println(myNumbers[1][0]);
    Serial.print("Строка 1, элемент 1: ");
    Serial.println(myNumbers[1][1]);
    Serial.print("Строка 1, элемент 2: ");
    Serial.println(myNumbers[1][2]);

    Serial.print("Строка 2, элемент 0: ");
    Serial.println(myNumbers[2][0]);
    Serial.print("Строка 2, элемент 1: ");
    Serial.println(myNumbers[2][1]);
    Serial.print("Строка 2, элемент 2: ");
    Serial.println(myNumbers[2][2]);
  }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //