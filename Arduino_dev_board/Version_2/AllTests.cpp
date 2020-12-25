// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// All tests for Arduino Dev Boards V.2
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
#include <NewPing.h>
#include "LedControl.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // Библиотека I2C дисплея

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Устанавливаем дисплей

/*
  Теперь настраиваем объект LedControl.
  Эти номера контактов, возможно, не будут работать в вашем проекте.
  Если необходимо, поменяйте их.

  5-ый контакт подключен к DIN.
  6-ый контакт подключен к CLK.
  7-ый контакт подключен к CS.
  У нас есть только один MAX72XX.
 */
LedControl lc = LedControl(5, 6, 7, 1);

const int PIN_ECHO = 14;
const int PIN_TRIG = 15;

NewPing sonar(PIN_TRIG, PIN_ECHO, 400);

void setup() {
  Serial.begin(9600);
  lcd.init(); // Инициализация LCD
  lcd.backlight();// Включаем подсветку дисплея
  lcd.begin(16, 2);  // Задаем размерность экрана
  //------------------------------------------------------------------------
  lc.shutdown(0, false);// Выключить энергосбережение, включить матрицу
  lc.setIntensity(0, 1);// Устанавлить яркость (0 ~ 15 возможных значений)
  lc.clearDisplay(0);// Очистить матрицу
  //------------------------------------------------------------------------
  pinMode(4, OUTPUT);
  for (int i = 8; i <= 12; ++i) {
    pinMode(i, OUTPUT);
  }
  //------------------------------------------------------------------------
  pinMode(PIN_TRIG, OUTPUT);
  //------------------------------------------------------------------------
}

void loop() {
  // Проверка экрана 1602
  lcd.clear(); // Очищаем экран перед получением нового значения
  lcd.setCursor(4, 0); // курсор на 4-й символ 1-й строки
  lcd.print("PWM"); // Тест на 1-й строке экрана
  lcd.setCursor(7, 1); // курсор на 7-й символ 2-й строки
  lcd.print("Hello, World!"); // Значения на 2-й строке экрана
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
  // Проверка сонара
  Serial.print("Sonar: ");
  Serial.println(sonar.ping_cm());
  // Проверка кнопок
  /*
  bool button1 = digitalRead(13);
  bool button2 = digitalRead(16);
  bool button3 = digitalRead(17);
  Serial.print("Button 1: ");
  Serial.print(button1);
  Serial.print(" ");
  Serial.print("Button 2: ");
  Serial.print(button2);
  Serial.print(" ");
  Serial.print("Button 3: ");
  Serial.println(button3);
  delay(20);
  */
  // Проверка потенциометра
  /*
  int pot = A7;
  int val = analogRead(pot);
  Serial.println(val);
  */
  // ----------------------------------
  // Проверка группы светодиодов
  for (int i = 8; i <= 12; ++i) {
    digitalWrite(i, !digitalRead(i));
    delay(150);
  }
  // ----------------------------------
  // Проверка динамика

  digitalWrite(4, HIGH);
  delay(500);
  digitalWrite(4, LOW);
  delay(500);

}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //