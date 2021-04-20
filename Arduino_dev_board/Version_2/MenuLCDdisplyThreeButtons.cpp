// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// Простой алгоритм счётчика нажатий 3-х кнопок. Перелистывание пунсктов меню на дисплее
// Известные проблемы: не стабильно работает вход в пунст меню
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
#include <Arduino.h>
#include "Button_Simple.h"
#include <LiquidCrystal_I2C.h> // Библиотека I2C дисплея
#include <DallasTemperature.h> // Работа датчика t C
#include <NewPing.h> // Для работы Сонара HC-SR04
#include "LedControl.h" // Для работы 8х8 светодиодной матрицы
#include <Wire.h>

// pin 2 для датчика t на Arduino
const int ONE_WIRE_BUS = 2;

// Шина I2C для работы датчика t
OneWire oneWire(ONE_WIRE_BUS);

// Передача c шины на датчик t
DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Устанавливаем дисплей

Button_Simple button13(13); // Пин кнопки перелистывания вверз
Button_Simple button16(16); // Пин кнопки входа в меню
Button_Simple button17(17); // Пин кнопки перелистывания вниз

// Верхний и нижний лимиты счётчика
const int LIMIT_UP = 4;
const int LIMIT_DOWN = 0;

// Пины для подключения Сонара HC-SR04
const int PIN_ECHO = 14;
const int PIN_TRIG = 15;

NewPing sonar(PIN_TRIG, PIN_ECHO, 400); // Объект Сонара HC-SR04

LedControl lc = LedControl(5, 6, 7, 1); // Объект 8х8 светодиодной матрицы

// Функция 8х8 светодиодной матрицы
void ledMatrix();

// Функция динамика
void voice(int on);
void voiceTest();

// Функция мотора
const int MOTOR_PWM = 3;
void motor(int pwm);

void setup() {
  Serial.begin(9600);
  // Экран 1602
  lcd.init(); // Инициализация LCD
  lcd.backlight();// Включаем подсветку дисплея
  lcd.begin(16, 2);  // Задаем размерность экрана
  lcd.clear(); // Очищаем экран перед получением нового значения
   // Сонар HC-SR04
  pinMode(PIN_TRIG, OUTPUT);
  // Светодиодная матрица 8х8
  lc.shutdown(0, false);// Выключить энергосбережение, включить матрицу
  lc.setIntensity(0, 1);// Устанавлить яркость (0 ~ 15 возможных значений)
  lc.clearDisplay(0);// Очистить матрицу
}

void loop() {
  //voice(255);
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
    lcd.setCursor(0, 0);      // курсор на 4-й символ 1-й строки
    lcd.print("  Choose menu   "); // Тест на 1-й строке экрана
    lcd.setCursor(0, 1);  // курсор/строка
    lcd.print("Menu Temperature:"); // Тест на 2-й строке экрана
    if (click16 == 1) {
      lcd.setCursor(0, 0);      // курсор/строка
      lcd.print("Curient t C     "); // Тест на 1-й строке экрана
      lcd.setCursor(5, 1);
      lcd.print("           ");
      lcd.setCursor(0, 1);
      lcd.print(sensors.getTempCByIndex(0)); // Значение t на 2-й строке экрана
      delay(250);
    }
    else { break; }
    break;
  case 1:
    lcd.setCursor(2, 0);      // курсор на 4-й символ 1-й строки
    lcd.print("  Choose menu   "); // Тест на 1-й строке экрана
    lcd.setCursor(0, 1);
    lcd.print("Menu Motor:     ");
    if (click16 == 1) {
      lcd.setCursor(0, 0);      // курсор/строка
      lcd.print("    Motor pwm   "); // Тест на 1-й строке экрана
      lcd.setCursor(0, 1);
      lcd.print("     start      ");
      motor(255);
      delay(1000);
    }
    else { break; }
    motor(0);
    break;
  case 2:
    lcd.setCursor(2, 0);      // курсор на 4-й символ 1-й строки
    lcd.print("  Choose menu   "); // Тест на 1-й строке экрана
    lcd.setCursor(0, 1);
    lcd.print("Menu Voice:     ");
    if (click16 == 1) {
      lcd.setCursor(0, 0);      // курсор/строка
      lcd.print("   Voice beep   "); // Тест на 1-й строке экрана
      lcd.setCursor(0, 1);
      lcd.print("      beep      ");
      delay(100);
      voice(155);
    }
    else { break; }
    voice(0);
    break;
  case 3:
    lcd.setCursor(2, 0);      // курсор на 4-й символ 1-й строки
    lcd.print("  Choose menu   "); // Тест на 1-й строке экрана
    lcd.setCursor(0, 1);
    lcd.print("8x8 led matrix:");
    if (click16 == 1) {
      lcd.setCursor(0, 0);      // курсор/строка
      lcd.print("      Matrix    "); // Тест на 1-й строке экрана
      lcd.setCursor(0, 1);
      lcd.print("     Start      ");
      delay(100);
      ledMatrix();
    }
    else { break; }
    break;
  case 4:
    lcd.setCursor(2, 0);      // курсор на 4-й символ 1-й строки
    lcd.print("  Choose menu   "); // Тест на 1-й строке экрана
    lcd.setCursor(0, 1);
    lcd.print("Menu Sonar:     ");
    if (click16 == 1) {
      lcd.setCursor(0, 0); // курсор/строка
      lcd.print("      Sonar     "); // Тест на экране дисплея
      lcd.setCursor(0, 1); // курсор/строка
      lcd.print("distance: "); // Тест на экране дисплея
      lcd.setCursor(12, 1);
      lcd.print(sonar.ping_cm());
      lcd.setCursor(15, 1); // курсор/строка
      lcd.print(" "); // Тест на экране дисплея
      delay(100);
    }
    else { break; }
    break;
  default:
    lcd.setCursor(2, 0);      // курсор на 4-й символ 1-й строки
    lcd.print("  Choose menu   "); // Тест на 1-й строке экрана
    lcd.setCursor(0, 1);
    lcd.print("Menu 1:         ");
    break;
  }
  //Serial.println(COUNT); // Для дианостики
}

void ledMatrix() {
  // Проверка 8х8 светодиодной матрицы
  //lc.setLed(0, 3, 4, true);
  lc.setRow(0, 0, B11111111);
  lc.setRow(0, 1, B11111111);
  lc.setRow(0, 2, B11100111);
  lc.setRow(0, 3, B11011011);
  lc.setRow(0, 4, B11100111);
  lc.setRow(0, 5, B11111111);
  lc.setRow(0, 6, B11111111);
  lc.setRow(0, 7, B11111111);
}

void voice(int on) {
  // Проверка динамика
  analogWrite(4, on);
  delay(150);
  analogWrite(4, 0);
  delay(150);
}

void motor(int pwm) {
  // Проверка мотора
  analogWrite (MOTOR_PWM, pwm);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
