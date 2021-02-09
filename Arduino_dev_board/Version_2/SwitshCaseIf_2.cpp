// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Управление ArduinoDevBoard 2.0 c 3-кнопок
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

const int BUTTON_13 = 13;
const int BUTTON_15 = 15;
const int BUTTON_16 = 16;

void setup() {
    Serial.begin(9600);
    // Настройка встроенных светодтодов
    for (int i = 8; i <= 12; ++i) {
        pinMode(i, OUTPUT);
    }
}

void loop() {
    bool buttonState13 = digitalRead(BUTTON_13);
    bool buttonState15 = digitalRead(BUTTON_15);
    bool buttonState16 = digitalRead(BUTTON_16);
    int choose = 0;
    if      (buttonState13 == true) { choose = 13; }
    else if (buttonState15 == true) { choose = 15; }
    else if (buttonState16 == true) { choose = 16; }
    else    { choose = 0; }
    switch (choose)
    {
    case 13:
        Serial.println(choose);
        break;
    case 15:
        Serial.println(choose);
        break;
    case 16:
        Serial.println(choose);
        break;
    default:
        Serial.println(choose);
        break;
    }
    Serial.println(choose);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
