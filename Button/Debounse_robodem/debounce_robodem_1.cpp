#include <Arduino.h>
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Учебный пример использования библиотеки антидребезга Button_Simple от компании РОБОДЕМ
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Button_Simple.h>

Button_Simple button(11);

void setup() {
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  static int click = 0;
  button.scan();
  while (button.clicked()) {
    if (++click >= 2) { click = 0; }
  }
  if (click == 1) { digitalWrite(3, HIGH); }
  else { digitalWrite(3, LOW); }
  Serial.println(click);
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //