// Мигаем светодиодом при помощи функции времени и оператора while
// V 1.0
unsigned long CurrentTime; 
unsigned long HighTime;
unsigned long LowTime;

void setup()
{
  pinMode(13 , OUTPUT); // Настраиваем пин 13 как ВЫХОД
}

void loop()
{
  CurrentTime = millis();  // Присваиваем переменной per1 возвращённое количество времени с начала выполнения программы
  HighTime = CurrentTime + 50; // Присваиваем переменной per2 сумму per1 + 50
  LowTime = CurrentTime + 1000;  // Присваиваем переменной per3 сумму per1 + 500 
  while (CurrentTime < HighTime) // Пока per1 < per2
  {
    digitalWrite(13, HIGH);  // Включаем светодиод
    CurrentTime= millis(); // Снова присваиваем per1 возвращённое время с начала выполнения программы
  }
  while (CurrentTime < LowTime) // Пока per1 < per3
  {
    digitalWrite(13, LOW);  // Выключаем светодиод
    CurrentTime = millis();  // Снова присваиваем per1 возвращённое время с начала выполнения программы
  }
}
