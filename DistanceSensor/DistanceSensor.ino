/* 
  Arduino Distance sensor
  Using an HC-SR04 ultrasonic sensor
  and an LCD display
*/

#include <LiquidCrystal.h>

// declare the lcd
LiquidCrystal lcd(8, 7, 6,5,4,3);

const int triggerPin = 10;
const int echoPin = 9;

void setup() {
  lcd.begin(16,2);

  // declare the pins
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration;
  int cm;


  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(3);
  digitalWrite(triggerPin, LOW);

  // get the duration using the echo pin
  duration = pulseIn(echoPin, HIGH);

  // convert microseconds to cm: 
  // speed of sound: 1 cm in 29 microseconds
  cm = duration / 29 / 2;

  // display data:
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("Distance:");

  lcd.setCursor(5, 1);
  lcd.print(cm);
  lcd.print(" cm");

  delay(100);
}
