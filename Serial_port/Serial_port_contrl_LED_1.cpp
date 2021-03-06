int led=13; // Объявляем переменную для светодиода на пин 13
char data;  // Объяавляем переменную для хранения символьных данных

void setup()
{
  Serial.begin(9600); //Устанавливаем скорость соединения с монитором порта
  pinMode(led, OUTPUT); // Настраиваем пин светодиода как ВЫХОД
}

void loop()
{
  if (Serial.available() > 0) // Если в монитор порта введены данные
  {
    data = Serial.read(); // Записываем их в переменную data
    if (data == '1')  // Если данные в переменной data совпадают с 1
    {
      digitalWrite(led, 1); // Включаем светодиод
      Serial.println("LED ON"); // Отправляем в монитор порта сообщение
    }
    else if (data == '0') // Иначе если данные в переменной совпадают с 0
    {
      digitalWrite(led, 0); // Выключаем светодиод
      Serial.println("LED OFF");  // Отправляем в монитор порта сообщение
    }
  }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
