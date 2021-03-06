// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Управление светодиодом при помощи потенциометра
// Опорное максимальное напряжение на входе АЦП Arduino соответствует значению 1023 (напряжение 5V)
// Аргумент функции analogWrite() находится в диапазоне 0...255
// Функция map(value, fromLow, fromHigh, toLow, toHigh), где value - преобразуемое значение
// fromLow и fromHigh - нижняя и верхняя границы текущего диапазона
// toLow и toHigh - нижняя и верхняя границы нового диапазона
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

void setup() {
  pinMode(10, OUTPUT);
}

void loop() {
  int knob = analogRead(0); // Потенциометр подключён к A0
  knob = map (knob, 0, 1023, 0, 255); // Пребразуем значение из 0...1023 в 0...255
  analogWrite(10, knob); // Управляем светодиодом
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //