// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// Простой алгоритм счётчика нажатий 2-х кнопок. Перелистывание пунсктов меню на дисплее
// Известные проблемы: счётчик считает от 0 и не попадает в индекс массива. Накладывются
// друг на друга слова
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
#include <Arduino.h>
#include "Button_Simple.h"
#include <LiquidCrystal_I2C.h> // Библиотека I2C дисплея

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Устанавливаем дисплей

Button_Simple button13(13); // Пин кнопки
Button_Simple button16(16); // Пин кнопки
Button_Simple button17(17); // Пин кнопки

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
  // Пока не знаю как мне войти в меню по нажатию кнопки А2
  while (button16.clicked()) {
    if (++click16 >= 2) { click13 = 0; } // Счётчик с ограничителем (0/1)
    if (click13 == 1) {  }
  }
  while (COUNT >= LIMIT_UP) { COUNT = LIMIT_UP; break; } // Ограничение инкремента
  while (COUNT <= LIMIT_DOWN) { COUNT = LIMIT_DOWN; break;  } // Ограничение декремента
  Serial.println(COUNT); // Для дианостики
  switch (COUNT)
  {
  case 0:
    lcd.clear(); // Очищаем экран перед получением нового значения
    lcd.setCursor(2, 0);      // курсор на 4-й символ 1-й строки
    lcd.print("Choose menu"); // Тест на 1-й строке экрана
    lcd.setCursor(0, 1);  // курсор/строка
    lcd.print("Menu Temperature:"); // Тест на 2-й строке экрана
    break;
  case 1:
    lcd.clear(); // Очищаем экран перед получением нового значения
    lcd.setCursor(2, 0);      // курсор на 4-й символ 1-й строки
    lcd.print("Choose menu"); // Тест на 1-й строке экрана
    lcd.setCursor(0, 1);
    lcd.print("Menu Motor:");
    break;
  case 2:
    lcd.setCursor(2, 0);      // курсор на 4-й символ 1-й строки
    lcd.print("Choose menu"); // Тест на 1-й строке экрана
    lcd.setCursor(0, 1);
    lcd.print("Menu Voice:");
    break;
  case 3:
    lcd.setCursor(2, 0);      // курсор на 4-й символ 1-й строки
    lcd.print("Choose menu"); // Тест на 1-й строке экрана
    lcd.setCursor(0, 1);
    lcd.print("Menu 8x8 led matrix:");
    break;
  case 4:
    lcd.setCursor(2, 0);      // курсор на 4-й символ 1-й строки
    lcd.print("Choose menu"); // Тест на 1-й строке экрана
    lcd.setCursor(0, 1);
    lcd.print("Menu Sonar:");
    break;
  default:
    lcd.setCursor(2, 0);      // курсор на 4-й символ 1-й строки
    lcd.print("Choose menu"); // Тест на 1-й строке экрана
    lcd.setCursor(0, 1);
    lcd.print("Menu 1:");
    break;
  }
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
