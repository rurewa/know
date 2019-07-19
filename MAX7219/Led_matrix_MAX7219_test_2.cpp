#include <Arduino.h>
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Тест для светодиодной матрицы 8х8 MAX7219
// Вариант 2
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <LedControl.h>

LedControl lc=LedControl(5, 6, 7, 1);
unsigned long delaytime=20;

void car()
{
  byte car[4]={B00111100, B11111110, B11111111, B01000100};

  for(int i=8; i>=0; i--)
  {
    lc.clearDisplay(0);
    lc.setRow(0, 4, car[0]>>i);
    lc.setRow(0, 5, car[1]>>i);
    lc.setRow(0, 6, car[2]>>i);
    lc.setRow(0, 7, car[3]>>i);
    delay(100);
  }
  delay(500);

  for(int i=0; i<=8; i++)
  {
    lc.clearDisplay(0);
    lc.setRow(0, 4, car[0]<<i);
    lc.setRow(0, 5, car[1]<<i);
    lc.setRow(0, 6, car[2]<<i);
    lc.setRow(0, 7, car[3]<<i);
    delay(100);
  }
}

void sineWave() {
  for(int i=0; i<200; i++)
  {
    lc.clearDisplay(0);
    for(int x=0; x<8; x++)
    {
      float y = (sin((float)(x+i)/1.57)*3.1)+3.57;
      if (y - (int)y >= 0.5)
      {
        y = ceil(y);
      } else {
        y = floor(y);
      }
      lc.setLed(0, (int)(y), x, true);
    }
    delay(60);
  }
}

void windmill()
{
  for(int i=0; i<40; i++)
  {
    lc.clearDisplay(0);
    lc.setRow(0,0,B01000001);
    lc.setRow(0,1,B00100010);
    lc.setRow(0,2,B00100100);
    lc.setRow(0,3,B00011000);
    lc.setRow(0,4,B01011000);
    lc.setRow(0,5,B10001000);
    lc.setRow(0,6,B00000100);
    lc.setRow(0,7,B00000010);
    delay(100);
    lc.clearDisplay(0);
    lc.setRow(0,0,B00001000);
    lc.setRow(0,1,B00001000);
    lc.setRow(0,2,B00001000);
    lc.setRow(0,3,B11111000);
    lc.setRow(0,4,B00011111);
    lc.setRow(0,5,B00010000);
    lc.setRow(0,6,B00010000);
    lc.setRow(0,6,B00010000);
    delay(100);
    lc.clearDisplay(0);
    for (int x=0; x<8; x++)
    {
      lc.setLed(0, x, x, true);
    }
    for (int x=7; x>=0; x--)
    {
      lc.setLed(0, 7-x, x, true);
    }
    delay(100);
  }
}

void christmasTree()
{
  lc.setRow(0,0,B00011000);
  lc.setRow(0,1,B00011000);
  lc.setRow(0,2,B00111100);
  lc.setRow(0,3,B00111100);
  lc.setRow(0,4,B01111110);
  lc.setRow(0,5,B01111110);
  lc.setRow(0,6,B00011000);
  lc.setRow(0,7,B00111100);
  delay(200);

  for(int i=0; i<40; i++)
  {
    lc.setRow(0,1,B00001000);
    lc.setRow(0,4,B01111100);
    lc.setRow(0,5,B00111110);
    delay(50);
    lc.setRow(0,1,B00011000);
    lc.setRow(0,4,B01111110);
    lc.setRow(0,5,B01111110);
    delay(50);
  }

  lc.clearDisplay(0);

  for (int x=0; x<8; x++)
  {
    lc.setLed(0, x, x, true);
    delay(100);
  }
  for (int x=7; x>=0; x--)
  {
    lc.setLed(0, 7-x, x, true);
    delay(100);
  }

  delay(1000);
}

void hoHoHo()
{
  for(int i=0; i<3; i++)
  {
    lc.setRow(0,0,B10000000);
    lc.setRow(0,1,B10000000);
    lc.setRow(0,2,B10000000);
    lc.setRow(0,3,B10000110);
    lc.setRow(0,4,B11101111);
    lc.setRow(0,5,B10101001);
    lc.setRow(0,6,B10101111);
    lc.setRow(0,7,B10100110);
    delay(1000);
    lc.clearDisplay(0);
    delay(500);
  }
}

void growingSquares()
{
  for(int i=0; i<5; i++)
  {
      lc.setRow(0,3,B00011000);
      lc.setRow(0,4,B00011000);
      delay(70);
      lc.clearDisplay(0);

      lc.setRow(0,2,B00111100);
      lc.setRow(0,3,B00111100);
      lc.setRow(0,4,B00111100);
      lc.setRow(0,5,B00111100);
      delay(70);
      lc.clearDisplay(0);

      lc.setRow(0,1,B01111110);
      lc.setRow(0,2,B01111110);
      lc.setRow(0,3,B01111110);
      lc.setRow(0,4,B01111110);
      lc.setRow(0,5,B01111110);
      lc.setRow(0,6,B01111110);
      delay(70);
      lc.clearDisplay(0);

      lc.setRow(0,0,B11111111);
      lc.setRow(0,1,B11111111);
      lc.setRow(0,2,B11111111);
      lc.setRow(0,3,B11111111);
      lc.setRow(0,4,B11111111);
      lc.setRow(0,5,B11111111);
      lc.setRow(0,6,B11111111);
      lc.setRow(0,7,B11111111);
      delay(70);
      lc.clearDisplay(0);

      lc.setRow(0,1,B01111110);
      lc.setRow(0,2,B01111110);
      lc.setRow(0,3,B01111110);
      lc.setRow(0,4,B01111110);
      lc.setRow(0,5,B01111110);
      lc.setRow(0,6,B01111110);
      delay(70);
      lc.clearDisplay(0);

      lc.setRow(0,2,B00111100);
      lc.setRow(0,3,B00111100);
      lc.setRow(0,4,B00111100);
      lc.setRow(0,5,B00111100);
      delay(70);
      lc.clearDisplay(0);

      lc.setRow(0,3,B00011000);
      lc.setRow(0,4,B00011000);
      delay(70);
      lc.clearDisplay(0);

      delay(200);
  }
}

void oscillateBrightness()
{
  for(int row=0;row<8;row++)
  {
    lc.setRow(0,row,B11111111);
  }

  for(int j = 0; j<5; j++)
  {
    for(int i=0; i<16; i++)
    {
      lc.setIntensity(0, i);
      delay(60);
    }
    for(int i=15; i>=0; i--)
    {
      lc.setIntensity(0, i);
      delay(60);
    }
    lc.shutdown(0, true);
    delay(200);
    lc.shutdown(0, false);
  }

  lc.clearDisplay(0);
  lc.setIntensity(0, 15);
}

void flashAllLeds()
{
  for(int i=0;i<5;i++)
  {
    for(int row=0;row<8;row++)
    {
      lc.setRow(0,row,B11111111);
    }
    delay(200);
    lc.clearDisplay(0);
    delay(200);
  }
}

void lightLedsRandomly()
{
  lc.clearDisplay(0);

  // Light all leds randomly.
  for(int i=0; i<100; i++)
  {
    lc.setLed(0, random(0, 8), random(0, 8), true);
    delay(30);
  }

  // Light different leds randomly
  for(int j=0; j<50; j++)
  {
    lc.clearDisplay(0);
    for(int i=0; i<100; i++)
    {
      lc.setLed(0, random(0, 8), random(0, 8), true);
    }
    delay(50);
  }
}

void swipeColumns()
{
  for(int i=0; i<2; i++)
  {
    for(int col=0;col<8;col++)
    {
      delay(delaytime);
      lc.setColumn(0,col,B11111111);
      delay(delaytime);
      lc.setColumn(0,col,(byte)0);
    }
    for(int col=7;col>=0;col--)
    {
      delay(delaytime);
      lc.setColumn(0,col,B11111111);
      delay(delaytime);
      lc.setColumn(0,col,(byte)0);
    }
  }

  for(int col=0;col<8;col++)
  {
    delay(delaytime);
    lc.setColumn(0,col,B11111111);
  }
  delay(200);
}

void swipeRows()
{
  lc.clearDisplay(0);

  for(int i=0; i<2; i++)
  {
    for(int row=0;row<8;row++)
    {
      delay(delaytime);
      lc.setRow(0,row,B11111111);
      delay(delaytime);
      lc.setRow(0,row,(byte)0);
    }
    for(int row=7;row>=0;row--)
    {
      delay(delaytime);
      lc.setRow(0,row,B11111111);
      delay(delaytime);
      lc.setRow(0,row,(byte)0);
    }
  }

  for(int row=0;row<8;row++)
  {
    delay(delaytime);
    lc.setRow(0,row,B11111111);
  }
  delay(200);
}

void showCountdownFrame(byte frame[])
{
  lc.setIntensity(0, 0);
  delay(100);

  for(int i=0; i<8; i++)
  {
    lc.setRow(0, i, frame[i]);
  }

  // Show
  for(int i=0; i<16; i++)
  {
    lc.setIntensity(0, i);
    delay(50);
  }

  // Oscillate intensity
  for(int j = 0; j<3; j++)
  {
    for(int i=15; i>5; i--)
    {
      lc.setIntensity(0, i);
      delay(20);
    }
    for(int i=5; i<16; i++)
    {
      lc.setIntensity(0, i);
      delay(20);
    }
  }
}

void countdown()
{
  byte five[8]={B0,B111100,B100000,B111000,B100,B100,B111000,B0};
  byte four[8]={B0,B100100,B100100,B100100,B111110,B100,B100,B0};
  byte three[8]={B0,B111100,B100,B111100,B100,B111100,B0,B0};
  byte two[8]={B0,B111100,B100,B111100,B100000,B111100,B0,B0};
  byte one[8]={B0,B1000,B11000,B1000,B1000,B1000,B1000,B0};
  byte go[8]={B0,B100111,B1010101,B110111,B10000,B1010000,B100000,B0};

  showCountdownFrame(five);
  showCountdownFrame(four);
  showCountdownFrame(three);
  showCountdownFrame(two);
  showCountdownFrame(one);
  showCountdownFrame(go);
}

void setup()
{
  lc.shutdown(0,false);
  lc.setIntensity(0,15);
  lc.clearDisplay(0);
}

void loop()
{
  countdown();
  swipeColumns();
  swipeRows();
  lightLedsRandomly();
  flashAllLeds();
  oscillateBrightness();
  growingSquares();
  hoHoHo();
  christmasTree();
  windmill();
  sineWave();
  car();

  delay(1000);
}
