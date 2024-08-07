#include <LiquidCrystal_I2C.h>

#include <Wire.h>

#include <Keypad.h>
#define greenled 6
#define redled 7
String text="";
byte sloupce[4]={8,9,10,11};
byte radky[4]={2,3,4,5};
char znaky[4][4]{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
Keypad keypad(makeKeymap(znaky),radky,sloupce,4,4);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0,0);
lcd.print("zadejte heslo:");
char znak=keypad.getKey();
if(znak){
  if(znak!='*'){
    if(znak!='#'){
      text+=znak;
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print(text);
    }
  }
  Serial.println(text);
}
if(znak=='*'){
  text="";
  lcd.clear();
}
if(znak=='#'){
  if(text==String(1234)){
    lcd.setCursor(0,1);
    lcd.print("otevreno");
    digitalWrite(greenled,HIGH);
  }else{
    lcd.setCursor(0,1);
    lcd.print("spatne heslo");
    digitalWrite(redled,HIGH);
  }
  delay(3000);
  lcd.clear();
  text="";
  digitalWrite(greenled,LOW);
  digitalWrite(redled,LOW);
}
}