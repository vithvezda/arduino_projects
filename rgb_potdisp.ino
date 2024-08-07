#include <Wire.h>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
const int redbut=2;
const int greenbut=3;
const int bluebut=4;
const int red=9;
const int green=10;
const int blue=11;
void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  for(int i=9;i<=11;i++){
    pinMode(i,OUTPUT);
  }
  for(int j=2;j<=4;j++){
    pinMode(j,INPUT);
  }
 lcd.setCursor(0,0);
 lcd.print("red=");lcd.print(0);
 lcd.setCursor(7,0);
 lcd.print("green=");lcd.print(0);
 lcd.setCursor(5,1);
 lcd.print("blue=");lcd.print(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(digitalRead(redbut)==HIGH){
    int pot=analogRead(A0);
    int val=map(pot,0,1021,0,255);
    analogWrite(red,val);
    lcd.setCursor(0,0);
    lcd.print("red=");lcd.print(val);
    if(val<10){
      lcd.setCursor(5,0);
      lcd.print("  ");
    }
    if(val<100){
      lcd.setCursor(6,0);
      lcd.print(" ");
    }
  }
  while(digitalRead(greenbut)==HIGH){
    int pot=analogRead(A0);
    int val=map(pot,0,1021,0,255);
    analogWrite(green,val);
    lcd.setCursor(7,0);
    lcd.print("green=");lcd.print(val);
    if(val<10){
      lcd.setCursor(14,0);
      lcd.print("  ");
    }
    if(val<100){
      lcd.setCursor(15,0);
      lcd.print(" ");
    }
  }
  while(digitalRead(bluebut)==HIGH){
    int pot=analogRead(A0);
    int val=map(pot,0,1021,0,255);
    analogWrite(blue,val);
    lcd.setCursor(5,1);
    lcd.print("blue=");lcd.print(val);
    if(val<10){
      lcd.setCursor(11,1);
      lcd.print("  ");
    }
    if(val<100){
      lcd.setCursor(12,1);
      lcd.print(" ");
    }
  }
}
