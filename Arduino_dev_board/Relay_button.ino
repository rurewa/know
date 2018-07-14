// Arduino Nano Relay
// V 1.0

void setup()
{
    pinMode(12, OUTPUT);
}

void loop()
{
    int button1 = digitalRead(7);
    if (button1 == LOW)
    {
        digitalWrite(12, HIGH);
    }
    else
    {
        digitalWrite(12, LOW);
    }
}
