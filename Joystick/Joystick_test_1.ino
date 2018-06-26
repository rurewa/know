// Joystick test
// V 1.0

void setup()
{
  // Скорость передачи данных в монитор порта
  Serial.begin(9600);
  // Настраиваем пин 2 как ВХОД с подключением 
  // встроенного в Arduino подтягивающего резистора
  pinMode(2, INPUT_PULLUP);
}

void loop()
{
  // Считываем в переменную значения с А0
  int valueX = analogRead(0); 
  // Посылаем сообщение в монитор порта
  Serial.print("X: ");
  Serial.print(valueX);
  // Считываем в переменную значения с А1
  int valueY = analogRead(1);
  // Посылаем сообщение в монитор порта
  Serial.print(" | Y: ");
  Serial.print(valueY);
  // Считываем в переменную значения с пин 2
  int buttonZ = digitalRead(2);
  buttonZ = buttonZ ^ 1;
  // Посылаем сообщение в монитор порта
  Serial.print(" | SW: ");
  Serial.println(buttonZ);
  delay(300);  // Задержка
}
