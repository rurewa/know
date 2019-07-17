// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Учебный пример использования флагов в программировании. Строим дом.
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
// Фундамент
bool foundStart = false; // Флаг начала строительства фундамента
bool foundEnd = false; // Флаг завершения строительства фундамента
// Стены
bool wallStart = false; // Флаг начала строительства стен
bool wallEnd = false; // Флаг завершения строительства стен
// Крыша
bool roofStart = false; // Флаг начала строительства крыши
bool roofEnd =  false; // Флаг завершения строительства крыши
// Флаги синхронизации
bool flagFound = true;
bool flagWalls = true;
bool flagRoof = true;
// Прототипы функций
void printFound();
void printWalls();
void printRoof();

void setup() {
    Serial.begin(9600);
}

void loop() {
  // Начало строительства фундамента
  foundStart = true; // Поменяли значение флага, т.к. начали строительство
  if (foundStart == true) { // Проверяем, начато ли строительство?
     while(foundEnd != foundStart) { //Пока фундамент не построен
        foundEnd = true; // Строим. Теперь флаги синхронизированы
        printFound(); // Выводим на экран результат
    }
  }
  // Проверка завершения строительства фундамента
  if (foundStart == false) {
     while (flagFound == true) {
        flagFound = false; // Синхронизируем флаги
        printFound(); // Выводим на экран результат
     }
  }

  // Начало строительства стен
  wallStart = foundEnd; // Проверка состояния готовности фундамента
  if (wallStart == true) { // Если фундамент готов
     while (wallEnd != wallStart) { // Пока стены не построены
       wallEnd = true; // Строим стены. Теперь флаги синхронизированы
       printWalls(); // Выводим на экран результат
    }
  }
  // Проверка завершения строительства стен
  if (wallStart == false) {
     while (flagWalls == true) {
       flagWalls =  false;
       printWalls();
    }
  }

  // Начало строительства крыши
  roofStart = wallEnd;
  if (roofStart == true) {
     while (roofEnd != roofStart) {
       roofEnd = true;
       printRoof();
    }
  }
  // Проверка завершения строительства крыши
  if (roofStart == false) {
     while (flagRoof == true) {
       flagRoof =  false;
       printRoof();
    }
  }
}

void printFound() {
    Serial.print("foundStart: ");
    Serial.print(foundStart);
    Serial.print("  ");
    Serial.print("foundEnd: ");
    Serial.print(foundEnd);
}

void printWalls() {
    Serial.println("  ");
    Serial.print("wallStart: ");
    Serial.print(wallStart);
    Serial.print("  ");
    Serial.print("wallllEnd: ");
    Serial.print(wallEnd);
}

void printRoof() {
    Serial.println("  ");
    Serial.print("roofStart: ");
    Serial.print(roofStart);
    Serial.print("  ");
    Serial.print("roofsEnd: ");
    Serial.print(roofEnd);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //