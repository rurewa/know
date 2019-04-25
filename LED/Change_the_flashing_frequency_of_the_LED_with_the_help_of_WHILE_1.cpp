// Управление светодиодом при помощи функции времени
// V 1.0
unsigned long per1; 
unsigned long per2;
unsigned long per3;

void setup()
{
  pinMode(13 , OUTPUT); // Настраиваем пин 13 как ВЫХОД
}

void loop()
{
  per1 = millis();  // Присваиваем переменной per1 возвращённое количество времени с начала выполнения программы
  per2 = per1 + 50; // Присваиваем переменной per2 сумму per1 + 50
  per3 = per1 + 500;  // Присваиваем переменной per3 сумму per1 + 500 
  while (per1 < per2) // Пока per1 < per2
  {
    digitalWrite(13, 1);  // Включаем светодиод
    per1= millis(); // Снова присваиваем per1 возвращённое время с начала выполнения программы
  }
  while (per1 < per3) // Пока per1 < per3
  {
    digitalWrite(13 ,0);  // Выключаем светодиод
    per1 = millis();  // Снова присваиваем per1 возвращённое время с начала выполнения программы
  }
}