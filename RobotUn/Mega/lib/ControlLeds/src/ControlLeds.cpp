
#include <Arduino.h>
#include <ControlLeds.h>

void GrowingSquares::runState() // Растущий квадрат
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

void SineWave::runWave() // Синусоидная волна
{
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

void WindMill::runWindmill() // Ветряная мельница
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

void FlashAllLeds::runFlash() // Зажигаем все светодиоды
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

void LightLedsRandomly::runRandomly() // Зажигаем всетодиоды в случайном порядке
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

void SwipeColumns::runSwipeCol() // Скользящая полоса по колонке
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

void SwipeRows::runSwipeRows() // Скользящая полоса по ряду
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

void Countdown::showCountdownFrame(byte frame[]) // Обратный отчёт 5-0
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

void Countdown::countDown() // Обратный отчёт 5-0
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

void WiteOnMatrix::runSimbols() // Слово
{
  lc.setRow(0,0,R[0]);
  lc.setRow(0,1,R[1]);
  lc.setRow(0,2,R[2]);
  lc.setRow(0,3,R[3]);
  lc.setRow(0,4,R[4]);
  delay(delaytime);
  lc.setRow(0,0,O[0]);
  lc.setRow(0,1,O[1]);
  lc.setRow(0,2,O[2]);
  lc.setRow(0,3,O[3]);
  lc.setRow(0,4,O[4]);
  delay(delaytime);
  lc.setRow(0,0,B[0]);
  lc.setRow(0,1,B[1]);
  lc.setRow(0,2,B[2]);
  lc.setRow(0,3,B[3]);
  lc.setRow(0,4,B[4]);
  delay(delaytime);
  lc.setRow(0,0,O[0]);
  lc.setRow(0,1,O[1]);
  lc.setRow(0,2,O[2]);
  lc.setRow(0,3,O[3]);
  lc.setRow(0,4,O[4]);
  delay(delaytime);
  lc.setRow(0,0,D[0]);
  lc.setRow(0,1,D[1]);
  lc.setRow(0,2,D[2]);
  lc.setRow(0,3,D[3]);
  lc.setRow(0,4,D[4]);
  delay(delaytime);
  lc.setRow(0,0,E[0]);
  lc.setRow(0,1,E[1]);
  lc.setRow(0,2,E[2]);
  lc.setRow(0,3,E[3]);
  lc.setRow(0,4,E[4]);
  delay(delaytime);
  lc.setRow(0,0,M[0]);
  lc.setRow(0,1,M[1]);
  lc.setRow(0,2,M[2]);
  lc.setRow(0,3,M[3]);
  lc.setRow(0,4,M[4]);
  delay(delaytime);
  lc.setRow(0,0,0);
  lc.setRow(0,1,0);
  lc.setRow(0,2,0);
  lc.setRow(0,3,0);
  lc.setRow(0,4,0);
  delay(delaytime);
}
