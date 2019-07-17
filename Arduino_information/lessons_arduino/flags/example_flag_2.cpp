// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Учебный пример использования флагов в программировании. Строим дом.
// V 1.1
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
  // Проверяем, начато ли строительство?
  if (foundStart == true) {
     // Проверяем, завершено ли строительство? Если оно не завершено..
     while(foundEnd != foundStart) {
        foundEnd = true; // Завершаем. Теперь флаги синхронизированы
        printFound();
    }
  }
  // Проверка завершения строительства фундамента
  if (foundStart == false) {
     while (flagFound == true) {
        flagFound = false; // Синхронизируем флаги
        printFound();
     }
  }

  // Начало строительства стен
  wallStart = foundEnd;
  if (wallStart == true) {
     while (wallEnd != wallStart) {
       wallEnd = true;
       printWalls();
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
  roofStart  = wallEnd;
  if (roofStart == true) {
     while (roofEnd != roofStart) {
       roofEnd = true;
       printRoof();
    }
  }
  // Проверка завершения строительства стен
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
