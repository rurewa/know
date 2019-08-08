// Controlling LEDs using switch and case
// V 1.0

void setup() 
{
  Serial.begin(9600); // Инициализируем монитор порта на  скорости 9600 бод
  for (int x=8; x<=12; ++x) // При помощи конструкции оператора for настраиваем пины с 8 по 12 как ВЫХОД
  {
    pinMode(x, OUTPUT);
  }  
}

void loop() 
{
  static bool msg_shown = false;

  if (Serial.available() > 0) // Если в монитор порта поступило значение больше, чем 0
  {
    int data = Serial.read(); // Объявляем переменную data и записываем в неё значение, введённое в монитор порта
    switch (data) // switch case операторы множественного выбора
    {
        case '1': // Если data равна 1, выполняем код
        for (int i=8; i<=12; ++i)
        {
          digitalWrite(i, HIGH);
          delay(50);
          digitalWrite(i, LOW);
          delay(50);
        }
        break; // Завершает выполнение цикла
        case '2': // Если data равна 2, выполняем код
        for (int i=12; i>=8; --i)
        {
          digitalWrite(i, HIGH);
          delay(50);
          digitalWrite(i, LOW);
          delay(50);
        }
        break;
        default: // Значение по умолчанию
        while (!msg_shown)
        {
          msg_shown = true;
          Serial.println("Press '1' / '2'");
        }  
    }    
  }  
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
