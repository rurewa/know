// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// Простой алгоритм счётчика нажатий 3-х кнопок. Перелистывание пунсктов меню на дисплее
// Известные проблемы: не стабильно работает вход в пунст меню
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
#include <Arduino.h>
#include "Button_Simple.h"
#include <LiquidCrystal_I2C.h> // Библиотека I2C дисплея

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Устанавливаем дисплей

Button_Simple button13(13); // Пин кнопки перелистывания вверз
Button_Simple button16(16); // Пин кнопки входа в меню
Button_Simple button17(17); // Пин кнопки перелистывания вниз

// Верхний и нижний лимиты счётчика
const int LIMIT_UP = 4;
const int LIMIT_DOWN = 0;

void setup()
{
  Serial.begin(9600);
  // Экран 1602
  lcd.init(); // Инициализация LCD
  lcd.backlight();// Включаем подсветку дисплея
  lcd.begin(16, 2);  // Задаем размерность экрана
  lcd.clear(); // Очищаем экран перед получением нового значения
}

void loop() {
  //lcd.clear(); // Очищаем экран перед получением нового значения
  static int click13 = 0; // Состояние режима кнопки 1/0
  static int click16 = 0; // Состояние режима кнопки 1/0
  static int click17 = 0; // Состояние режима кнопки 1/0
  button13.scan();        // Инициализация библиотеки
  button16.scan();        // Инициализация библиотеки
  button17.scan();        // Инициализация библиотеки
  static int COUNT = 0;   // Счётчик
  // Инкремент счётчика
  while (button17.clicked()) { // Если нажали
    if (++click17 >= 2) { click17 = 0; ++COUNT; } // Счётчик с ограничителем (0/1)
    if (click17 == 1) { ++COUNT; }
  }
  // Декремент счётчика
  while (button13.clicked()) {
    if (++click13 >= 2) { click13 = 0; --COUNT; } // Счётчик с ограничителем (0/1)
    if (click13 == 1) { --COUNT; }
  }
  while (button16.clicked()) {
    if (++click16 >= 2) { click16 = 0; } // Счётчик с ограничителем (0/1)
  }
  while (COUNT >= LIMIT_UP) { COUNT = LIMIT_UP; break; } // Ограничение инкремента
  while (COUNT <= LIMIT_DOWN) { COUNT = LIMIT_DOWN; break;  } // Ограничение декремента
  switch (COUNT)
  {
  case 0:
    lcd.setCursor(2, 0);      // курсор на 4-й символ 1-й строки
    lcd.print("Choose menu"); // Тест на 1-й строке экрана
    lcd.setCursor(0, 1);  // курсор/строка
    lcd.print("Menu Temperature:"); // Тест на 2-й строке экрана
    if (click16 == 1) {
      lcd.setCursor(0, 0);      // курсор/строка
      lcd.print("Curient t C     "); // Тест на 1-й строке экрана
      lcd.setCursor(0, 1);
      lcd.print("      30 C      ");
      delay(100);
    }
    else { break; }
    break;
  case 1:
    lcd.setCursor(2, 0);      // курсор на 4-й символ 1-й строки
    lcd.print("Choose menu"); // Тест на 1-й строке экрана
    lcd.setCursor(0, 1);
    lcd.print("Menu Motor:     ");
    if (click16 == 1) {
      lcd.setCursor(0, 0);      // курсор/строка
      lcd.print("    Motor pwm   "); // Тест на 1-й строке экрана
      lcd.setCursor(0, 1);
      lcd.print("    155 PWM     ");
      delay(100);
    }
    else { break; }
    break;
  case 2:
    lcd.setCursor(2, 0);      // курсор на 4-й символ 1-й строки
    lcd.print("Choose menu"); // Тест на 1-й строке экрана
    lcd.setCursor(0, 1);
    lcd.print("Menu Voice:     ");
    if (click16 == 1) {
      lcd.setCursor(0, 0);      // курсор/строка
      lcd.print("   Voice beep   "); // Тест на 1-й строке экрана
      lcd.setCursor(0, 1);
      lcd.print("      beep      ");
      delay(100);
    }
    else { break; }
    break;
  case 3:
    lcd.setCursor(2, 0);      // курсор на 4-й символ 1-й строки
    lcd.print("Choose menu"); // Тест на 1-й строке экрана
    lcd.setCursor(0, 1);
    lcd.print("8x8 led matrix:");
    if (click16 == 1) {
      lcd.setCursor(0, 0);      // курсор/строка
      lcd.print("      Matrix    "); // Тест на 1-й строке экрана
      lcd.setCursor(0, 1);
      lcd.print("     Start      ");
      delay(100);
    }
    else { break; }
    break;
  case 4:
    lcd.setCursor(2, 0);      // курсор на 4-й символ 1-й строки
    lcd.print("Choose menu"); // Тест на 1-й строке экрана
    lcd.setCursor(0, 1);
    lcd.print("Menu Sonar:     ");
    if (click16 == 1) {
      lcd.setCursor(0, 0);      // курсор/строка
      lcd.print("      Sonar     "); // Тест на 1-й строке экрана
      lcd.setCursor(0, 1);
      lcd.print("distance:       ");
      delay(100);
    }
    else { break; }
    break;
  default:
    lcd.setCursor(2, 0);      // курсор на 4-й символ 1-й строки
    lcd.print("Choose menu"); // Тест на 1-й строке экрана
    lcd.setCursor(0, 1);
    lcd.print("Menu 1:         ");
    break;
  }
  // Пока не знаю как мне войти в меню по нажатию кнопки А2
  //Serial.println(COUNT); // Для дианостики
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
