// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// All tests for Arduino Dev Boards V.2
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
#include <OneWire.h> // Для работы датчика t dc18b20
#include <DallasTemperature.h>
#include <NewPing.h> // Для работы Сонара HC-SR04
#include "LedControl.h" // Для работы 8х8 светодиодной матрицы
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // Библиотека I2C дисплея

// pin 2 для датчика t на Arduino
const int ONE_WIRE_BUS = 2;

// Шина I2C для работы датчика t
OneWire oneWire(ONE_WIRE_BUS);

// Передача c шины на датчик t
DallasTemperature sensors(&oneWire);

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
LedControl lc = LedControl(5, 6, 7, 1); // Объект экрана 1602

// Пины для подключения Сонара HC-SR04
const int PIN_ECHO = 14;
const int PIN_TRIG = 15;

NewPing sonar(PIN_TRIG, PIN_ECHO, 400); // Объект Сонара HC-SR04

// Функция Сонара
// Функция 8х8 светодиодной матрицы
// Функция 1602 экрана
// Функция динамика
// Функция датчика t
// Функция группы светодиодов
// Функция RGB-светодиода
// Функция потенциометра
// Функция мотора
// Функция кнопок

void setup() {
  Serial.begin(9600);
  // Датчик t
  Serial.println("Dallas Temperature IC Control Library Demo");
  // Инициализация библиотеки температурного датчика
  sensors.begin();
  // ----------------------------------------------------------------------
  // Экран 1602
  lcd.init(); // Инициализация LCD
  //lcd.backlight();// Включаем подсветку дисплея
  lcd.begin(16, 2);  // Задаем размерность экрана
  //------------------------------------------------------------------------
  // Светодиодная матрица 8х8
  lc.shutdown(0, false);// Выключить энергосбережение, включить матрицу
  lc.setIntensity(0, 1);// Устанавлить яркость (0 ~ 15 возможных значений)
  lc.clearDisplay(0);// Очистить матрицу
  //------------------------------------------------------------------------
  // Группа дискретных светодиодов
  pinMode(4, OUTPUT);
  for (int i = 8; i <= 12; ++i) {
    pinMode(i, OUTPUT);
  }
  //------------------------------------------------------------------------
  // Сонар HC-SR04
  pinMode(PIN_TRIG, OUTPUT);
  //------------------------------------------------------------------------
}

void loop() {
  // ----------------------------------------------------------------
  // Проверка мотора
  /*
  int motorPWM = 3;
  analogWrite (motorPWM, 85);
  */
  // ----------------------------------------------------------------
  // Датчик температуры
  // вызов sensor.requestTemperatures (), чтобы отправить запрос глобальной
  // температуры всем устройствам на шине
  Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures(); // Отправляем коменду для получения t
  Serial.println("DONE");
  Serial.print("Temperature for Device 1 is:: ");
  Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"?
  // ------------------------------------------------------------------
  // Проверка экрана 1602
  lcd.clear(); // Очищаем экран перед получением нового значения
  lcd.setCursor(0, 0); // курсор на 4-й символ 1-й строки
  lcd.print("Temperature:"); // Тест на 1-й строке экрана
  lcd.setCursor(2, 1); // курсор на 7-й символ 2-й строки
  lcd.print(sensors.getTempCByIndex(0)); // Значение t на 2-й строке экрана

  // -------------------------------------------------------------------
  // Проверка 8х8 светодиодной матрицы
  //lc.setLed(0, 3, 4, true);
  /*
  lc.setRow(0, 0, B11111111);
  lc.setRow(0, 1, B11111111);
  lc.setRow(0, 2, B11100111);
  lc.setRow(0, 3, B11011011);
  lc.setRow(0, 4, B11100111);
  lc.setRow(0, 5, B11111111);
  lc.setRow(0, 6, B11111111);
  lc.setRow(0, 7, B11111111);
  */
  // Проверка сонара
  /*
  Serial.print("Sonar: ");
  Serial.println(sonar.ping_cm());
  */
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
  /*
  for (int i = 8; i <= 12; ++i) {
    digitalWrite(i, !digitalRead(i));
    delay(150);
  }
  */
  // ----------------------------------
  // Проверка динамика
  /*
  digitalWrite(4, HIGH);
  delay(500);
  digitalWrite(4, LOW);
  delay(500);
  */
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //