#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop() {
  static int up = 0;
  static int down = 5;
  static unsigned long oneTime = millis();
  while(millis() >= oneTime) {
    analogWrite(9, up);
    up += down;
    // Когда up < 255 происходит приращение на 5. Когда up >=255
    // происходит выполнение up += -down
    if(up <= 0 || up >= 255) {
      down = -down; // Тут просто down -5 до тех пор, пока up <= 0
    }
    oneTime = millis() + 200;
    Serial.println(up);
  }
}