// Arduino_dev_board v 2.0
// Blinking LED control with potentiometer for Arduino_dev_board v 2.0
// V 1.0
const int pot = 7; // A7
int val = 0; // Analog
int valPWM = 0; // Digital

void setup()
{
    Serial.begin(9600);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
}

void loop()
{
  val = analogRead(pot);
  Serial.print("Analog: ");
  Serial.print(val);
  valPWM = analogRead(pot);
  valPWM = map(val, 0, 1023, 0, 255); // Преобразование аналогового значение в цивровое
  Serial.print(" Digitalg: ");
  Serial.println(valPWM);
  analogWrite(9, valPWM);
  analogWrite(10, valPWM);
  analogWrite(11, valPWM);
}
