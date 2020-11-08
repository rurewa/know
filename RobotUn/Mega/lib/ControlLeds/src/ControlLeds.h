// Заголовочный файл
// проверка, что библиотека еще не подключена
#ifndef ControlLeds_h	// если библиотека Button не подключена
#define ControlLeds_h	// тогда подключаем ее
#include <Arduino.h>
#include <LedControl.h>

class GrowingSquares // Растущий квадрат
{
  public:
    LedControl lc = LedControl(5, 6, 7, 1);
    unsigned long delaytime = 20;
    void runState();
};

class SineWave // Синусоидная волна
{
  public:
    LedControl lc = LedControl(5, 6, 7, 1);
    unsigned long delaytime = 20;
    void runWave();
};

class WindMill // Ветряная мельница
{
  public:
    LedControl lc = LedControl(5, 6, 7, 1);
    unsigned long delaytime = 20;
    void runWindmill();
};

class FlashAllLeds // Зажигаем все светодиоды
{
  public:
    LedControl lc = LedControl(5, 6, 7, 1);
    unsigned long delaytime = 20;
    void runFlash();
};

class LightLedsRandomly // Зажигаем всетодиоды в случайном порядке
{
  public:
    LedControl lc = LedControl(5, 6, 7, 1);
    unsigned long delaytime = 20;
    void runRandomly();
};

class SwipeColumns // Скользящая полоса по колонке
{
  public:
    LedControl lc = LedControl(5, 6, 7, 1);
    unsigned long delaytime = 20;
    void runSwipeCol();
};

class SwipeRows // Скользящая полоса по ряду
{
  public:
    LedControl lc = LedControl(5, 6, 7, 1);
    unsigned long delaytime = 20;
    void runSwipeRows();
};

class Countdown // Обратный отчёт 5-0
{
  public:
    LedControl lc = LedControl(5, 6, 7, 1);
    unsigned long delaytime = 20;
    void showCountdownFrame(byte frame[]);
    void countDown();
};

class WiteOnMatrix // Буквы и слово
{
  public:
    LedControl lc = LedControl(5, 6, 7, 1);
    unsigned long delaytime = 500;
    void runSimbols();
    // Буквы английского алфавита
    byte A[5]={ B01111111,B10001000,B10001000,B10001000,B01111111  };
    byte B[5]={ B11111111,B01001001,B01001001,B00110110,B00000000  };
    byte C[5]={ B01111110,B10000001,B10000001,B10000001,B01000010  };
    byte D[5]={ B01111111,B01000001,B01000001,B00111110,B00000000  };
    byte E[5]={ B11111110,B10010010,B10010010,B10010010,B00000000  };
    byte F[5]={ B01111111,B01001000,B01001000,B01001000,B00000000  };
    byte G[5]={ B01111110,B10000001,B10001001,B10001001,B01001110  };
    byte H[5]={ B01111111,B00001000,B00001000,B00001000,B01111111  };
    byte I[5]={ B00100001,B00100001,B00111111,B00100001,B00100001  };
    byte J[5]={ B00000110,B00000001,B00000001,B00000001,B11111110  };
    byte K[5]={ B11111111,B00011000,B00100100,B01000010,B10000001  };
    byte L[5]={ B11111111,B00000001,B00000001,B00000001,B00000001  };
    byte M[5]={ B11111100,B01000000,B00100000,B01000000,B11111100  };
    byte N[5]={ B00111111,B00010000,B00001000,B00000010,B00111111  };
    byte O[5]={ B01111110,B10000001,B10000001,B10000001,B01111110  };
    byte P[5]={ B11111111,B10001000,B10001000,B10001000,B01110000  };
    byte Q[5]={ B01111100,B10000010,B10000010,B10000011,B01111101  };
    byte R[5]={ B11111111,B10001000,B10001100,B10001010,B01110001  };
    byte S[5]={ B00110001,B01001001,B01001001,B01001001,B01000110  };
    byte T[5]={ B00100000,B00100000,B00111111,B00100000,B00100000  };
    byte U[5]={ B00111110,B00000001,B00000001,B00000001,B00111110  };
    byte V[5]={ B00111100,B00000010,B00000001,B00000010,B00111100  };
    byte W[5]={ B00111111,B00000010,B00000100,B00000010,B00111111  };
    byte X[5]={ B00010001,B00001010,B00000100,B00001010,B00010001  };
    byte Y[5]={ B11100000,B00010000,B00001111,B00010000,B11100000  };
    byte Z[5]={ B00010001,B00010011,B00010101,B00011001,B00010001  };
    byte r[5]={ B00111110,B00010000,B00100000,B00100000,B00010000  };
};

#endif
