#include <Arduino.h>
// 16X2 1602A LCD Display with I2C 
// with sonar, pot and servo
// v 1.0
// UNO: SDA - A4, SCL - A5
// MEGA: SDA - pin20, SCL - pin21
#include <Arduino.h>
#include <NewPing.h> // Библиотека для HC-SR04
#include <Servo.h> // Библиотека для серво
#include <Wire.h> // Библиотека для устройств I2C
#include <LiquidCrystal_I2C.h> // Библиотека для ЖК с I2C
/* Устанавливаем ЖК-дисплей 0x27 для 16-ти символовольного
и 2-строчного дисплея */
LiquidCrystal_I2C lcd(0x27,16,2);
Servo myservo; // Объект для серво
const int pot = 0;
const int trig = 11;
const int echo = 12;
// Настраиваем trig, echo и максимальное расстояние для HC-SR04
NewPing sonar(trig, echo, 400);
float val = 0; // Перевенная для значений с потенциометра

void setup()
{
  Serial.begin(9600); // Устанавливаем скорость для монитора порта
  myservo.attach(4); // Устанавливаем пин для серво
  pinMode(trig, OUTPUT);
  lcd.init(); // Инициализация LCD                    
  lcd.backlight();// Включаем подсветку дисплея
  lcd.begin(16, 2);  // Задаем размерность экрана
}
void loop()
{
  val = analogRead(pot); // Считываем хначения с потенциометра
  val = map (val, 0, 1023, 0, 179); // Преобразуем их в цифр.диапазон
  myservo.write(val); // Управляем серво
  Serial.print("Cm ");
  Serial.println(sonar.ping_cm()); // Отсылаем значения в монитор порта
  unsigned int uS2 = sonar.ping_cm();
  lcd.clear(); // Очищаем экран перед получением нового значения
  lcd.setCursor(4, 0); // курсор на 4-й символ 1-й строки
  lcd.print("DISTANCE"); // Тест на 1-й строке экрана
  lcd.setCursor(7, 1); // курсор на 7-й символ 2-й строки
  lcd.print(uS2); // Значения на 2-й строке экрана
  delay(100);
}
