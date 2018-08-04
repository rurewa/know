#include <Arduino.h>
#include <DebButton.h>
// Debounсe button for Arduino dev board 2.0
// V 1.0
/*
  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/Debounce
*/

DebButton button;

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  button.checkState(); // Для объекта button циклично работает метод checkState()
}
