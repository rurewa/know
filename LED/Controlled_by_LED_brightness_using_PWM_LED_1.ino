// Управление яркостью светодиода с помощью ШИМ
// V 1.0
const byte led = 9;  // Определяем константу led на выводе 9

void setup()
{
  pinMode(led, OUTPUT); // Настраиваем led на выход
}

void loop()
{
  for (int i=0; i<256; i++) // abalogWrite имеет значение от 0 до 255 (8-и разрядное значение)
  {
    analogWrite(led, i);  //
    delay(10);
  }
  for (int i=255; i>=0; i--)  //
  {
    analogWrite(led, i);  //
    delay(10);
  }
}
