#include <Servo.h>

Servo myservo;

int pos = 90;
int soundPin = A1;
int ldrPin = A0;
int sound = 0;
int light = 0;

void setup() {
  pinMode(ldrPin, INPUT);
  pinMode(soundPin, INPUT);
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  sound = analogRead(soundPin);
  light = analogRead(ldrPin);
  Serial.print("Sound: ");
  Serial.print(sound);
  Serial.print("  Light: ");
  Serial.println(light);
  if (sound >60 && light < 1100) {
    pos=180;
    myservo.write(pos);
    delay(5000);
    pos=0;
    myservo.write(pos);
    delay(5000);
  }
}

