// Программа управления сервоприводом
// при помощи джойстика

#include <Servo.h>  // Подключаем библиотеку
Servo myservo;  // Создаём объект сервопривода
const int led = 13; // Назначаем для светодиода D13
const int SWz = 2;  // Назначаем для кнокпи джойстика D2
const int VRx = 1;  // Назначаем для VRx A1
int data = 0; // Переменная для хранения значений джойстика
int button = 0; // Переменная для хранения значений кнопки

void setup()
{
  myservo.attach(9);  // Сервопривод на D9
  pinMode(led, OUTPUT); //
  // Кнопка как Вход с подключением внутреннего 
  // подтягивающего регистора
  pinMode(SWz, INPUT_PULLUP); 
}
void loop()
{
  // Считываем в переменную значения
  data = analogRead(VRx);
  // Преобразуем значение в нужный диапазон
  data = map (data, 0, 1023, 0, 179);
  // Управляем валом сервопривода
  myservo.write(data); 
  // Считываем значение с кнопки джойстика
  button = digitalRead(SWz);
  if (button == !LOW) // Если не нажата
  {
    digitalWrite(led, LOW); // Светодиод выключен
  }
  else  // Иначе
  {
    digitalWrite(led, HIGH);  // Светодиод включен
  }
}
