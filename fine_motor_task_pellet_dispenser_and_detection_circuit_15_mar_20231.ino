#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution for your stepper motor
const int ledPin = 12;  // the pin that the LED is attached to
const int irPin = 2;  // the pin that the IR Phototransistor is attached to
unsigned long previousTime = 0;
const unsigned long bufferTime = 30000; // 30 seconds buffer time

// initialize the stepper library on pins:
Stepper myStepper(stepsPerRevolution, 10, 11, 6, 7);

void setup() {
  pinMode(ledPin, OUTPUT);  // initialize the LED pin as an output
  pinMode(irPin, INPUT);  // initialize the IR Phototransistor pin as an input
  Serial.begin(9600);  // initialize serial communication at 9600 bits per second
}

void loop() {
  unsigned long currentTime = millis();
  // read the state of the IR Phototransistor
  int irState = digitalRead(irPin);

  // if the IR Phototransistor is tripped and 30 seconds have passed since the last activation,
  // turn on the LED and move the stepper motor 90 degrees
  if (irState == HIGH && currentTime - previousTime > bufferTime) {
    digitalWrite(ledPin, HIGH);  // turn on the LED
    myStepper.step(90);  // move the stepper motor 90 degrees
    previousTime = currentTime;
    delay(500);  // wait for half a second
  } else {
    digitalWrite(ledPin, LOW);  // turn off the LED
  }
}
