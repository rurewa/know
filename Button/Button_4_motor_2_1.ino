// Пины драйвера моторов
const int in1 = 16;
const int in2 = 17;
const int in3 = 18;
const int in4 = 19;
// ---------------------
// Кнопки пульта управления
const int butF = 3;
const int butL = 6;
const int butR = 4;
const int butB = 5;
// ---------------------
// Переменные состояния кнопок
int FOWARD = 0;
int LEFT = 0;
int RIGHT = 0;
int BACK = 0;

void setup() 
{
    Serial.begin(9600); // Для диагностики
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
}

void loop() 
{
    // Считываем состояния кнопок
    FOWARD = digitalRead(butF);
    LEFT = digitalRead(butL);
    RIGHT = digitalRead(butR);
    BACK = digitalRead(butB);
    // ----------------------------
    // Управление движением
    if (FOWARD != LOW) // Вперёд
    {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
    }
    else if (LEFT != LOW) // Влево
    {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
    }
    else if (RIGHT != LOW) // Вправо
    {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
    }
    else if (BACK != LOW) // Назад
    {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
    }
    else // Стоп
    {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
    }
    /*// участок кода для диагностики
    Serial.print("FOWARD: ");
    Serial.print(FOWARD, DEC);
    Serial.print("  LEFT: ");
    Serial.print(LEFT, DEC);
    Serial.print("  RIGHT: ");
    Serial.print(RIGHT, DEC);
    Serial.print("  BACK: ");
    Serial.println(BACK, DEC);
    delay(1500);*/
}
