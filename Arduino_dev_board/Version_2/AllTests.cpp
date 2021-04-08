// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// All tests for Arduino Dev Boards V.2
// V 1.2
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
LedControl lc = LedControl(5, 6, 7, 1); // Объект 8х8 светодиодной матрицы

// Пины для подключения Сонара HC-SR04
const int PIN_ECHO = 14;
const int PIN_TRIG = 15;

NewPing sonar(PIN_TRIG, PIN_ECHO, 400); // Объект Сонара HC-SR04

// Функция Сонара
void sonarFunc();
// Функция 8х8 светодиодной матрицы
void ledMatrix();
// Функция 1602 экрана
void display1602();
// Функция динамика
void voice();
// Функция датчика t
void temerature();
// Функция группы светодиодов
void ledsGroup();
// Функция RGB-светодиода
void rgbLed();
// Функция потенциометра
void potValue();
// Функция мотора
void motor();
// Функция кнопок
void buttons();

const int MOTOR_PWM = 3;

void setup() {
  Serial.begin(9600);
  // Датчик t
  Serial.println("Dallas Temperature IC Control Library Demo");
  // Инициализация библиотеки температурного датчика
  sensors.begin();
  // ----------------------------------------------------------------------
  // Экран 1602
  lcd.init(); // Инициализация LCD
  lcd.backlight();// Включаем подсветку дисплея
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
  pinMode(MOTOR_PWM, OUTPUT);
}

void loop() {
  //sonarFunc();
  //temerature();
  //ledMatrix();
  //voice();
  //display1602();
  //ledsGroup();
  //potValue();
  //motor();
  //buttons();
  rgbLed();
}
void temerature() {
  // Датчик температуры
  // вызов sensor.requestTemperatures (), чтобы отправить запрос глобальной
  // температуры всем устройствам на шине
  Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures(); // Отправляем коменду для получения t
  Serial.println("DONE");
  Serial.print("Temperature for Device 1 is:: ");
  Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"?
}

void display1602() {
  // Проверка экрана 1602
  lcd.clear(); // Очищаем экран перед получением нового значения
  lcd.setCursor(0, 0); // курсор на 4-й символ 1-й строки
  lcd.print("Temperature:"); // Тест на 1-й строке экрана
  lcd.setCursor(2, 1); // курсор на 7-й символ 2-й строки
  lcd.print(sensors.getTempCByIndex(0)); // Значение t на 2-й строке экрана
}

void voice() {
  // Проверка динамика
  digitalWrite(4, HIGH);
  delay(500);
  digitalWrite(4, LOW);
  delay(500);
}

void sonarFunc() {
  // Проверка сонара
  Serial.print("Sonar: ");
  Serial.println(sonar.ping_cm());
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

void ledsGroup() {
  // Проверка группы светодиодов
  for (int i = 8; i <= 12; ++i) {
    digitalWrite(i, !digitalRead(i));
    delay(150);
  }
}

void potValue() {
  // Проверка потенциометра
  int pot = A7;
  int val = analogRead(pot);
  Serial.println(val);
}

void motor() {
  // Проверка мотора
  analogWrite (MOTOR_PWM, 254);
}

void buttons() {
  // Проверка кнопок
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
}

void rgbLed() {
  for (int i = 9; i <= 11; ++i) {
    digitalWrite(i, !digitalRead(i));
    delay(350);
  }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
