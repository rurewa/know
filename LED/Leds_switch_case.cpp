// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Управление кнопками с применением конструкции switch ... case
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

void led8() {
  digitalWrite(8, HIGH);
}

void led9() {
  digitalWrite(9, HIGH);
}

void led10() {
  digitalWrite(10, HIGH);
}

void ledsOFF() {
  for (int i=8; i<=10; i++) {
    digitalWrite(i, LOW);
  }
}

void led_off() {
  digitalWrite(8, LOW);
}

void led_off() {
  digitalWrite(8, LOW);
}

void foo() {
  bool state13 = false, state16 = false, state17 = false; // Кнопки
  int button1 = 13, button2 = 16, button3 = 17;
  int Flag = 0; // Просто флаг

  state13 = digitalRead(button1); // Записываем состояние в переменную
  state16 = digitalRead(button2);
  state17 = digitalRead(button3);

  if (state13 == true) Flag = 0;
  else if (state16 == true) Flag = 1;
  else if (state17 == true) Flag = 2;
  else if (state13 == false && state16 == false && state17 == false) Flag = 3; // Если все кнопки не нажаты

  switch(Flag) // Сравниваем переменную с несколькими значениями
  {
    case 0:
      led8(); // Включаем 8 светодиод
    break;
    case 1:
      led9(); // Включаем 9 светодиод
    break;
    case 2:
      led10(); // Включаем 10 светодиод
    break;
    default:
      ledsOFF(); // Все светодиоды выключены
    break;
  }
}

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  foo();
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //