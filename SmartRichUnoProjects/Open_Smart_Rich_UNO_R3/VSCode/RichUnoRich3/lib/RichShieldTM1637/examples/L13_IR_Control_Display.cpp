/************************************************* ************************************************** ******
* OPEN-SMART Rich Shield Lesson 13: Infrared remote control and display
* You can learn how to recoginze the key on the IR remote control and display the number on the display.
*
* The following functions are available:

* buzzer.on();//turn on the buzzer
* buzzer.off();//turn off the buzzer

* IR.enableIRIn(); // Start the receiver
* IR.decode();//if no result, it return 0, otherwise it return 1; .
* IR.resume(); // so that it can receive the next value
* IR.isReleased();//if the button is not released yet, it return 1; otherwise it return 0;
*
* disp.init (); // initialization
* disp.display (int Decimal);   // display range: -999 ~ 9999
* Управление с ИК-пульта. v 1.0
************************************************** **************************************************/
#include <Arduino.h>
#include <Wire.h>
#include "RichShieldTM1637.h"
#include "RichShieldIRremote.h"
#include "RichShieldPassiveBuzzer.h"

const int PassiveBuzzerPin = 3; //the SIG pin of the module is connected with D3 of OPEN-SMART UNO R3
//There is no white waterproof sticker on the passive buzzer
PassiveBuzzer buz(PassiveBuzzerPin);

const int RECV_PIN = 2;//the SIG pin of Infrared Receiver is connected with D2 of  OPEN-SMART UNO R3
IRrecv IR(RECV_PIN);

const int CLK = 10; //CLK of the TM1637 IC connect to D10 of Arduino
const int DIO = 11; //DIO of the TM1637 IC connect to D11 of Arduino
TM1637 disp(CLK, DIO);

unsigned char num = 0;

void setup() {
    Serial.begin(9600);
    disp.init();//The initialization of the display
    IR.enableIRIn(); // Start the receiver
}

void loop() {
    if (IR.decode()) { //If a valid key code is detected
        if(IR.isReleased()) { //If it is not the repeat code for long press
            buz.playTone(2500, 50); //every time you press the key, the buzzer will beep 2500Hz for 50ms
            switch(IR.keycode) {
                case KEY_ZERO:
                    num = 0;
                    Serial.println(KEY_ZERO);
                    break;
                case KEY_ONE:
                    num = 1;
                    Serial.println(KEY_ONE);
                    break;
                case KEY_TWO:
                    num = 2;
                    Serial.println(KEY_TWO);
                    break;
                case KEY_THREE:
                    num = 3;
                    Serial.println(KEY_THREE);
                    break;
                case KEY_FOUR:
                    num = 4;
                    Serial.println(KEY_FOUR);
                    break;
                case KEY_FIVE:
                    num = 5;
                    Serial.println(KEY_FIVE);
                    break;
                case KEY_SIX:
                    num = 6;
                    Serial.println(KEY_SIX);
                    break;
                case KEY_SEVEN:
                    num = 7;
                    Serial.println(KEY_SEVEN);
                    break;
                case KEY_EIGHT:
                    num = 8;
                    Serial.println(KEY_EIGHT);
                    break;
                case KEY_NINE:
                    num = 9;
                    Serial.println(KEY_NINE);
                    break;
                case KEY_PLUS:
                    num = num+1;
                    Serial.println(KEY_PLUS);
                    break;
                case KEY_MINUS:
                    num = num-1;
                    Serial.println(KEY_MINUS);
                    break;
                default:
                    break;
            }
        disp.display(num);
        delay(100);   //buzzer beep for 100ms
    }
    IR.resume(); // Receive the next value
    }
}
/*********************************************************************************************************
The end of file
*********************************************************************************************************/
