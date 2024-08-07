const int redbut=2;
const int greenbut=3;
const int bluebut=4;
const int red=9;
const int green=10;
const int blue=11;
void setup() {
  // put your setup code here, to run once:
  for(int i=9;i<=11;i++){
    pinMode(i,OUTPUT);
  }
  for(int j=2;j<=4;j++){
    pinMode(j,INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  while(digitalRead(redbut)==HIGH){
    int pot=analogRead(A0);
    int val=map(pot,0,1023,0,255);
    analogWrite(red,val);
  }
  while(digitalRead(greenbut)==HIGH){
    int pot=analogRead(A0);
    int val=map(pot,0,1023,0,255);
    analogWrite(green,val);
  }
  while(digitalRead(bluebut)==HIGH){
    int pot=analogRead(A0);
    int val=map(pot,0,1023,0,255);
    analogWrite(blue,val);
  }
}
    
  

