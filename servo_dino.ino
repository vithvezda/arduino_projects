#include <Servo.h>

Servo myservo;
int servopos=180;
int pot;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  myservo.write(servopos);
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.write(servopos);
  pot=analogRead(A0);
  if(pot<=140){
    myservo.write(150);
    delay(150);
  }
}
