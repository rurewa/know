// Buttons leds no rattling
// V 1.0
const int led1 = 9;
const int inPin1 = 7;

void setup()
{
    pinMode(led1, OUTPUT);
}

void loop()
{
    if (digitalRead(inPin1) == LOW)
    {
        digitalWrite(led1, LOW);
    }
    else
    {
        digitalWrite(led1, HIGH);
    }
}
