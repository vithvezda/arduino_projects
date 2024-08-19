#include <Wire.h>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  // put your setup code here, to run once:
lcd.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
int volt=analogRead(A0)-analogRead(A1);
float disp=(float(volt)/1022.0)*5.0;
lcd.print(disp);
lcd.setCursor(6,0);
lcd.print("V");
delay(100);
lcd.clear();
}
