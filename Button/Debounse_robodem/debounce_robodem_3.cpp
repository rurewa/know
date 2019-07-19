#include <Arduino.h>
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Учебный пример использования библиотеки антидребезга Button_Simple от компании РОБОДЕМ
// V 3.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Button_Simple.h>

Button_Simple button(11); // Пин кнопки

void setup() {
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  static bool is_on = false; // Состояние режима 1/0
  button.scan(); // Инициализация библиотеки
  if (button.clicked()) {
    is_on = !is_on;
    if (is_on == true) {
      digitalWrite(3, HIGH);
    }
    else {
      digitalWrite(3, LOW);
    }
    //digitalWrite(3, is_on ? HIGH : LOW);
  }
  Serial.println(is_on);
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //