#include <LiquidCrystal.h>

// declare the lcd
LiquidCrystal lcd(1, 2, 4,5,6,7);

// use constants for pins
const int temp_sensor_pin = A0;
const int buzzer = 9;

// to buzz the buzzer periodically
int buzz_timer = 0;

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  // process data
  int temp_sensor_value = analogRead(temp_sensor_pin);
  int voltage = temp_sensor_value * (5/1024.0) * 1000;
  float temp = voltage / 10.0 - 60;

  // output on the lcd
  lcd.print("voltage: ");
  lcd.print(voltage);
  lcd.print(" mV");

  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");

  // buzz it
  buzz_timer+=2;
  if(buzz_timer == 10){
    tone(buzzer, 512, 50);
  }
  else if(buzz_timer == 20){
    tone(buzzer, 640, 50);
    buzz_timer = 0;
  }

  delay(200);
  lcd.clear();
}
