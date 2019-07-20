#include <Arduino.h>
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Резисторный пульт Keyes ad key K845037
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

//*********************
int sensorValue; // Переменная значений нажатий
int key = 0; // Флаг определения номеров кнопок
//*********************

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(A0); // Считывание данных с аналогового пина А0

  if (sensorValue == 0) { key = 1; }
  else if (sensorValue >= 141 && sensorValue <= 142) { key = 2; }
  else if (sensorValue >= 326 && sensorValue <= 327) { key = 3; }
  else if (sensorValue >= 499 && sensorValue <= 500) { key = 4; }
  else  if (sensorValue >= 738 && sensorValue <= 739) { key = 5; }
  else { key = 6; }
  switch (key)
  {
  case 1:
    Serial.println("Button 1 ON");
    break;
  case 2:
    Serial.println("Button 2 ON");
    break;
  case 3:
    Serial.println("Button 3 ON");
    break;
  case 4:
    Serial.println("Button 4 ON");
    break;
  case 5:
    Serial.println("Button 5 ON");
  break;
  default:
    Serial.println("Buttons OFF");
    break;
  }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //