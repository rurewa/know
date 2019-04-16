// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Программа движения робота по линии от Тимофея
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

#include <Arduino.h>
#include <motions.h>

void setup() {
    pinMode(ENA, OUTPUT);
    pinMode(MotorRight, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(MotorLeft, OUTPUT);
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
    // Serial.begin(9600);
}

void loop() {  
    int SL = digitalRead(SensorLeft);
    int SR = digitalRead(SensorRight);
    int SM = digitalRead(SensorMiddle);
    int Flag = 0;
    if(SL == LOW && SM == HIGH && SR == LOW) Flag = 0; // Режим:Вперед
    else if(SL == LOW && SM == HIGH && SR == HIGH) Flag = 1; // Режим:Вправо
    else if(SL == HIGH && SM == HIGH && SR == LOW) Flag = 2; // Режим:Влево
    else if(SL == LOW && SM == LOW && SR == HIGH) Flag = 1; // Режим:Вправо
    else if(SL == HIGH && SM == LOW && SR == LOW) Flag = 2; // Режим:Влево
    else if(SL == HIGH && SM == HIGH && SR == HIGH) Flag = 3; // Режим:Вперед и влево
    else Flag = 1; // Режим:Вправо
    switch(Flag)
    {
        case 0:
            forward();
        break;
        case 1:
            right();
        break;
        case 2:
            left();
        break;
        case 3:
            forward_left();
        break;
    }
    delay(75);
}
// ПРИМЕЧАНИЯ
/*
    Режимы:
    0 - Вперед
    1 - Вправо
    2 - Влево
    3 - Вперед и влево
*/
// Отладка датчиков
/*
    Serial.print(SL);
    Serial.print(",");
    Serial.print(SM);
    Serial.print(",");
    Serial.print(SR);
*/
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //