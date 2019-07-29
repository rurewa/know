// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Учебный пример использования извлечения данных из массива
// WritingToArrayElements
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

const int ARRAY_LENGHT = 5; // Размер массива
int myNumbers[ARRAY_LENGHT] = { 155, 3, 68, 20, -1 }; // Содержимое массива
char elementIndex = 0;

void setup() {
    Serial.begin(9600);
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
    Serial.print("Enter element: ");
}

void loop() {
  while (Serial.available() > 0) {
    elementIndex = Serial.read(); // Ввожу № элемента массива
    Serial.print(" Element: ");
    Serial.println(elementIndex); // Показываю № элемента массива
    Serial.print(" Extract: ");
    Serial.print(myNumbers[elementIndex - '0']); // Показываю число элемента массива
    /*т.е. я ввожу, к примеру 1, что в ASCII равно 49-ми. А ноль в ASCII это 48.
    Получается 49-48 (elementIndex - '0') = 1. И т.д.  */
  }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //