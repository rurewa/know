// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Учебный пример использования флагов в программировании. Строим дом.
// V 1.1
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
// Фундамент
bool foundStart = false; // Флаг начала строительства фундамента
bool foundEnd = false; // Флаг завершения строительства фундамента
// Стены
bool wallsStart = false; // Флаг начала строительства стен
bool wallsEnd = false; // Флаг завершения строительства стен

// Крыша
bool roofStart = false; // Флаг завершения строительства крыши
bool roofEnd =  false; // Флаг завершения строительства крыши

bool flag = true; // Флаг синхронизации

void printFound();

void setup() {
    Serial.begin(9600);
}

void loop() {
  // Начали строительство фундамента
  foundStart = true; // Поменяли значение флага, т.к. начали строительство
  // Проверяем, начато ли строительство?
  if(foundStart == true) {
    // Проверяем, завершено ли строительство? Если оно не завершено..
    while(foundEnd != foundStart) {
        foundEnd = true; // Завершаем. Теперь флаги синхронизированы
        printFound();
      }
  }
  // Проверка завершения строительства фундамента
  if(foundStart == false) {
    while(flag == true) {
        flag = false; // Синхронизируем флаги
        printFound();
      }
  }

  // Начали строительство стен
  /*wallsStart = foundEnd; // Проверка, если фундамент построен, что начинаем строительсво
  if (wallsStart == !wallsEnd) // Проверяем, начато ли строительство?
    {
    if (wallsEnd != wallsStart) // Проверяем, завершено ли строительство? Если оно не завершено..
      {
        wallsEnd = wallsStart;
        Serial.println("");
        Serial.print("wallsStart: ");
        Serial.print(wallsStart);
        Serial.print("  ");
        Serial.print("wallsEnd: ");
        Serial.print(wallsEnd);
      }
    }
  roofStart = wallsEnd;
  if (roofStart == !roofEnd)
    {
    if (roofEnd != roofStart)
      {
        roofEnd = roofStart;
        Serial.println("");
        Serial.print("roofStart: ");
        Serial.print(roofStart);
        Serial.print("  ");
        Serial.print("roofEnd: ");
        Serial.print(roofEnd);
      }
    }*/
}

void printFound() {
  Serial.print("foundStart: ");
  Serial.print(foundStart);
  Serial.print("  ");
  Serial.print("foundEnd: ");
  Serial.print(foundEnd);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
