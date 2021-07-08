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

#include <Wire.h>
	 
#include "RichShieldPassiveBuzzer.h"

#define PassiveBuzzerPin 3//the SIG pin of the module is connected with D3 of OPEN-SMART UNO R3
                     //There is no white waterproof sticker on the passive buzzer
PassiveBuzzer buz(PassiveBuzzerPin);

//------------------------------------
//This is a macro definition of bass, midrange, and treble frequencies
#define NOTE_L1  262
#define NOTE_L2  294
#define NOTE_L3  330
#define NOTE_L4  349
#define NOTE_L5  392
#define NOTE_L6  440
#define NOTE_L7  494
#define NOTE_M1  523
#define NOTE_M2  587
#define NOTE_M3  659
#define NOTE_M4  698
#define NOTE_M5  784
#define NOTE_M6  880
#define NOTE_M7  988
#define NOTE_H1  1046
#define NOTE_H2  1175
#define NOTE_H3  1318
#define NOTE_H4  1397
#define NOTE_H5  1568
#define NOTE_H6  1760
#define NOTE_H7  1976
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

void setup(void)
{
  //sing the tunes
  sing();
}
void loop()
{

}

void sing() {
  // iterate over the notes of the melody:
    int size = sizeof(doubleTiger) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 500 / tempo[thisNote];//a beat for 0.5 second

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

