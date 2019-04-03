#include <Button.h>
// Debounse button
// V 1.0

Button button;

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  button.checkState();
}
