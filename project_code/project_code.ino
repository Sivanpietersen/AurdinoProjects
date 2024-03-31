#include <Arduino_BuiltIn.h>

const int ledPins[] = {2, 3, 4, 5, 6};
const int buzzerPin = 7;
const int buttonPin = 8;

int pattern = 0;
bool buttonState = 0;
bool lastButtonState = 0;

void pattern1() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(200);
    digitalWrite(ledPins[i], LOW);
  }
}

void pattern2() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
  tone(buzzerPin, 1000);
  delay(500);
  noTone(buzzerPin);
  delay(500);
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      pattern++;
      if (pattern > 1) {
        pattern = 0;
      }
    }
    lastButtonState = buttonState;
  }

  switch (pattern) {
    case 0:
      pattern1();
      break;
    case 1:
      pattern2();
      break;
    default:
      break;
  }
}
