char data;  // Объявляем переменную типа char для хранения символьных значений

void setup()
{
  Serial.begin(9600); // Устанавливаем скорость соединения с монитором порта
}

void loop()
{
  if (Serial.available() > 0) // Если что-то введено в монитор порта
  {
    data = Serial.read(); // Тогда введённое считываем в переменную data
    Serial.print(data); // И отправляем то, что ввели обратно в монитор портаa 
  }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
