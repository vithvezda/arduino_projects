#include <LiquidCrystal_I2C.h>

#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int score1=0;
int score2=0;

int leftbut=2;
int midbut=3;
int rightbut=4;
int greenled=9;
int redled=8;
int blueled=5;
int buzzer=10;
void setup() {
  // put your setup code here, to run once:
lcd.begin();
lcd.print(0);
lcd.setCursor(15,0);
lcd.print(0);
for(int i=2;i<=5;i++){
  pinMode(i,OUTPUT);
}
for(int j=8;j<=10;j++){
  pinMode(j,OUTPUT);
}
}


void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(midbut)==HIGH){
    digitalWrite(redled,LOW);
    digitalWrite(blueled,LOW);
    digitalWrite(greenled,LOW);
    noTone(buzzer);
    
    int time=random(2000,5000);
    int ran=0;
    while(ran<=time){
      if(digitalRead(leftbut)==HIGH){
            for(int k=0;k<=4;k++){
              digitalWrite(redled,HIGH);
              delay(100);
              digitalWrite(redled,LOW);
              delay(100);
            }
            score1--;
            lcd.setCursor(0,0);
            lcd.print("  ");
            lcd.setCursor(0,0);
            lcd.print(score1);
          }
          if(digitalRead(rightbut)==HIGH){
            for(int k=0;k<=4;k++){
              digitalWrite(greenled,HIGH);
              delay(100);
              digitalWrite(greenled,LOW);
              delay(100);
            }
            score2--;
            lcd.setCursor(14,0);
            lcd.print("  ");
            lcd.setCursor(14,0);
            lcd.print(score2);
          }
        delay(1);
        ran++;
    }
    int game=random(1,3);
    if (game==1){
      digitalWrite(blueled,HIGH);
    }else if(game==2){
      tone(buzzer,600);
    }
  }
  
  if(digitalRead(leftbut)==HIGH){
      if(digitalRead(greenled)==LOW){
        if(digitalRead(redled)==LOW){
          digitalWrite(redled,HIGH);
          score1++;
          lcd.setCursor(0,0);
          lcd.print("  ");
          lcd.setCursor(0,0);
          lcd.print(score1);
        }
      }
    }
  else if(digitalRead(rightbut)==HIGH){
      if(digitalRead(redled)==LOW){
        if(digitalRead(greenled)==LOW){
          digitalWrite(greenled,HIGH);
          score2++;
          lcd.setCursor(14,0);
          lcd.print("  ");
          lcd.setCursor(14,0);
          lcd.print(score2);
          delay(500);
        }
      }
    }
  
}
