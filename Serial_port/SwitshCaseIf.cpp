// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Управление Arduino из Монитора порта
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

void setup() {
    Serial.begin(9600);
    for (int i = 8; i <= 12; ++i) {
        pinMode(i, OUTPUT);
    }
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
}

void loop() {
    while (Serial.available() > 0) {
        int userNum = 0;
        userNum = Serial.read();
        switch (userNum)
        {
        case '1':
            //Serial.print(userNum);
            Serial.println(" :Case 1");
            break;
        case '2':
            //Serial.print(userNum);
            Serial.println(" :Case 2");
            break;
        case '3':
            //Serial.print(userNum);
            Serial.println(" :Case 3");
            for (int i = 8; i <= 12; ++i) {
                digitalWrite(i, !digitalRead(i));
                delay(150);
            }
            break;
        default:
            //Serial.println(userNum);
            Serial.println(" :Other");
            for (int i = 8; i <= 12; ++i) {
                digitalWrite(i, HIGH);
            }
            break;
        }
    }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

