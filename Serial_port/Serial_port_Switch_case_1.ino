char data = 0;  // Объявляем переменную для хранения символьной информации
int led=13;

void setup() 
{
  Serial.begin(9600); // Устанавливаем скорость порта монитора
  pinMode(led, OUTPUT);  // Устанавливаем для пин 13 режим ВЫХОД  
}

void loop() 
{
  if (Serial.available() > 0) // Ожидаем ввод данных в монитор порт 
  {    
    data = Serial.read(); // Записываем введённые данные
  
    switch (data) // Сравниваем полученные данные с 1, 2 и 3
    {
      case '1': // Если совпало с 1
        digitalWrite(led, HIGH); // Включаем светодиод
        Serial.println("LED is ON");  // Посылаем в монитор порта сообщение
      break;  // Принудительный выход из оператора switch
      
      case '2': // Если совпало с 2
        digitalWrite(led, LOW);  // Выключаем светодиод
        Serial.println("LED is OFF"); // Посылаем сообщение в монитор порта
      break;  // Принудительный выход из оператора switch
      
      case '3': // Если совпало с 3, посылаем сообщения в монитор порта
        Serial.println("------- MENU -------"); 
        Serial.println("1. Switch LED on.");
        Serial.println("2. Switch LED off.");
        Serial.println("3. This menu.");
        Serial.println("--------------------");
      break;  // Принудительный выход из оператора switch
    } 
  } 
}
