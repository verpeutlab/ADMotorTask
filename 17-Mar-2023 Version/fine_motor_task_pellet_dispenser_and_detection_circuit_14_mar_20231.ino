// C++ code
//
#include <Servo.h>

int test = 0;

Servo servo_10;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT);
  pinMode(12, OUTPUT);
  servo_10.attach(10, 500, 2500);
}

void loop()
{
  // Blinks built-in LED for power confirmation
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)

  // Reads and blinks house light indication for rats
  if (digitalRead(2) < 1) {
    digitalWrite(12, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(12, LOW);
    // Buffer for how long between trials
    delay(10000); // Wait for 10000 millisecond(s)
  }

  // Detects rat movement, triggers food dispensal
  if (digitalRead(2) < 1) {
    servo_10.write(10);
    delay(10000); // Wait for 10000 millisecond(s)
  }
}