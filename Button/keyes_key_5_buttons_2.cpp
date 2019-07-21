#include <Arduino.h>
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Резисторный пульт Keyes ad key K845037 с однократным событием при нажатии
// 5V это от 1022 до 1023 аналогового значения
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
//#define TEST_ON //-- Расширенная диагностика
#define BRepos 1022 //-- 5 V, ни одна кнопка не нажата

const int _B1 = 0; // Кнопка 1
const int B2min = 141; // Кнопка 2
const int B2max = 142;
const int B3min = 326; // Кнопка 3
const int B3max = 327;
const int B4min =  499; // Кнопка 4
const int B4Max = 500;
const int B5Min = 738; // Кнопка 5
const int B5Max = 739;
//*********************
int sensorValue;
int oldkey = 0, key = 0;
//*********************
int buttonPushed(int val); // Прототип функции
//*********************
void setup() {
 Serial.begin(9600);
}

void loop() {
 sensorValue = analogRead(A0);
 if (sensorValue < BRepos)
 key = buttonPushed(sensorValue);
 else {
   oldkey = 0;
   }
 }

int buttonPushed(int val) {
  delay(50);
  if( val <= _B1 ) {
  if (oldkey != key) {
    Serial.println("Bouton 1 ON");
    oldkey = 1;
    }
  return 1;
  }
  else if ( val >= B2min and val <= B2max) {
  if (oldkey != key) {
    Serial.println("Bouton 2 ON");
    oldkey = 2;
    }
  return 2;
  }
  else if ( val >= B3min and val <= B3max) {
  if (oldkey != key) {
    Serial.println("Bouton 3 ON");
    oldkey = 3;
    }
  return 3;
  }
  else if ( val >= B4min and val <= B4Max ) {
  if (oldkey != key) {
    Serial.println("Bouton 4 ON");
    oldkey = 4;
    }
  return 4;
  }
  else if ( val >= B5Min and val <= B5Max) {
  if (oldkey != key) {
    Serial.println("Bouton 5 ON");
    oldkey = 5;
    }
  return 5;
  }
  else { //--
  #ifdef TEST_ON
  Serial.println(val);
  #endif
  return 0;
  }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
