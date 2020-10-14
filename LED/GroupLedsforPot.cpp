// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// Простая светодиодная волна от потенциометра
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
#include <Arduino.h>

<<<<<<< HEAD
const int POT= A7; // Аналоговый вход A7 для подключения потенциометра
// список контактов подключения светодиодной шкалы
const int PINS_LEDS[5] = {8, 9, 10, 11, 12};

void setup() {
  for(int i = 0; i <= 4 ; i++) {
    // Сконфигурировать пины светодиодов как выходы
=======
const int PINS_LEDS[5] = {8, 9, 10, 11, 12};

void setup() {
  for (int i = 0; i <= 4; i++) {
>>>>>>> master
    pinMode(PINS_LEDS[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
<<<<<<< HEAD
  int valPot = 0; // переменная для хранения значения потенциометра
  int countLeds = 0; // переменная для хранения значения шкалы
  valPot = analogRead(POT); // чтение данных потенциометра
  // масштабируем значение к интервалу 0-5
  countLeds = map(valPot, 0, 1023, 0, 5);
  // зажигаем светодиоды на шкале, равное countLeds
  for (int i = 0; i < 5; i++) {
    if(i < countLeds) { // зажигаем светодиод шкалы
=======
  const int PIN_POT = A7;
  int valPot = analogRead(PIN_POT);
  int countLeds = map (valPot, 0, 1023, 0, 5);

  for (int i = 0; i <= 5; i++) {
    if (i < countLeds) {
>>>>>>> master
      digitalWrite(PINS_LEDS[i], HIGH);
    }
    else {
      digitalWrite(PINS_LEDS[i], LOW);
    }
  }
  Serial.println(countLeds);
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
