#include <IRremote.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#include <Servo.h>
#define servopin 9
#define irpin 4

Servo myservo;
int servopos=0;

IRrecv receiver(irpin);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(servopin);
  myservo.write(servopos);
  receiver.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(receiver.decode(&results)){
    Serial.println(results.value,HEX);
    if(results.value==0xFFA857){
      if(servopos<90){
        for(int i=0;i<=89;i++){
        servopos++;
        myservo.write(servopos);
        delay(8);
        }
      }
    }
    else if(results.value==0xFFE01F){
      if(servopos>0){
        for(int i=0;i<=89;i++){
        servopos--;
        myservo.write(servopos);
        delay(8);
        }
      }
    }
  delay(100);
  receiver.resume();
  }
}
  
