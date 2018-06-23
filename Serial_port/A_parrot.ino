// A parrot
// V 1.0
char data = 0; // Знаковый тип данных

void setup() 
{
    Serial.begin(9600); // Количество бит./сек.
}

void loop() 
{
   if (Serial.available() > 0) // Ожидание ввода в монитор порта
   {
     data = Serial.read(); // Запись в переменную
     Serial.print(data); // Отправка обратно в монитор порта
   }     
}
