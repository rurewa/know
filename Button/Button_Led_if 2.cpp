// Управление светодиодом с кнопки (циклично)

const int led = 13; // переменная для светодиода на контакте 13
const int button = 2;  // переменная для кнопки на контакте 2

void setup() { 
  pinMode(led, OUTPUT); // настраиваем контакт для светодиода как выход
  pinMode(button, INPUT); // настраиваем контакт для кнопки как вход
} 

void loop() { 
  if(digitalRead(button) == HIGH) //если кнопка нажата
  {
  digitalWrite(led, HIGH);  //включаем светодиод 
  }
  else //если не нажата
  {
    digitalWrite(led, LOW); //выключаем 
  } 
}
