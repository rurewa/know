// Reflection sensor test for Nano motors
// V 1.0
const int ENA = 10;
const int in2 = 12;
const int Smidle = 7;
int SM;

void setup() 
{
    pinMode(ENA, OUTPUT);
    pinMode(in2, OUTPUT);
}

void loop() 
{
    SM = digitalRead(Smidle);
    if (SM == 0)
    {
        digitalWrite(in2, HIGH);
        analogWrite(ENA, 200);
    }
    else
    {
        digitalWrite(in2, LOW);
        analogWrite(ENA, 200);
    }
}
