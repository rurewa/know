/************************************************* *************************************************
* OPEN-SMART Rich Shield Lesson 2:  Passive buzzer to play tone of Chinese Double Tiger
* You can learn how to use a passive buzzer to play simple songs according to the notation.
*
* The following functions are available:
*
* playTone(long note, long millisecond); //The first parameter note is the frequency of note, unit is HZ; 
*                                       //millisecond is the duration of this tone, unit is ms.
*
************************************************** *******************************************************/
#include <Arduino.h>
#include <Wire.h>	 
#include "RichShieldPassiveBuzzer.h"

void sing();

const int PassiveBuzzerPin = 3;
PassiveBuzzer buz(PassiveBuzzerPin);

//------------------------------------
//This is a macro definition of bass, midrange, and treble frequencies
const int NOTE_L1 =  262;
const int NOTE_L2 =  294;
const int NOTE_L3 =  330;
const int NOTE_L4 =  349;
const int NOTE_L5 =  392;
const int NOTE_L6 =  440;
const int NOTE_L7 =  494;
const int NOTE_M1 =  523;
const int NOTE_M2 =  587;
const int NOTE_M3 =  659;
const int NOTE_M4 =  698;
const int NOTE_M5 =  784;
const int NOTE_M6 =  880;
const int NOTE_M7 =  988;
const int NOTE_H1 = 1046;
const int NOTE_H2 = 1175;
const int NOTE_H3 = 1318;
const int NOTE_H4 = 1397;
const int NOTE_H5 = 1568;
const int NOTE_H6 = 1760;
const int NOTE_H7 = 1976;
//-------------------------------------------
//musical notation of Two Tigers 
const static int doubleTiger[] = { 
    NOTE_M1,NOTE_M2,NOTE_M3,NOTE_M1, 
    NOTE_M1,NOTE_M2,NOTE_M3,NOTE_M1, 
    NOTE_M3,NOTE_M4,NOTE_M5, 
    NOTE_M3,NOTE_M4,NOTE_M5, 
    NOTE_M5,NOTE_M6,NOTE_M5,NOTE_M4,
    NOTE_M3,NOTE_M1, 
    NOTE_M5,NOTE_M6,NOTE_M5,NOTE_M4,
    NOTE_M3,NOTE_M1, 
    NOTE_M2,NOTE_L5,
    NOTE_M1,0,
    NOTE_M2,NOTE_L5,
    NOTE_M1,0
};
//-------------------------------------------
////note duration of Two Tigers, 2 is half a beat, 1 is a beat.
const static int tempo[] = { 
    2,2,2,2,
    2,2,2,2, 
    2,2,1, 
    2,2,1,  
    2,2,2,2,
    1,1,
    2,2,2,2,
    1,1,
    1,1,
    1,1,
    1,1,
    1,1
};

void setup(void) {
    //sing the tunes
    sing();
}

void loop() { }

void sing() {
    // iterate over the notes of the melody:
    int size = sizeof(doubleTiger) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
        int noteDuration = 500 / tempo[thisNote]; //a beat for 0.5 second
        buz.playTone(doubleTiger[thisNote], noteDuration);
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 0.30;
        delay(pauseBetweenNotes);
    }
}
/*********************************************************************************************************
The end of file
*********************************************************************************************************/

