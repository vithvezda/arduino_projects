void setup() {
  // put your setup code here, to run once:
for(int k=2;k<=7;k++){
  pinMode(k,OUTPUT);
}
}

void loop() {
  // put your main code here, to run repeatedly:
int sound=analogRead(A0);
int leds=map(sound,120,350,0,6);
ledon(leds);
}

void ledon(int pocet){
  for(int i=2;i<=pocet+1;i++){
    digitalWrite(i,HIGH);
  }
  for(int i=pocet+2;i<=8;i++){
    digitalWrite(i,LOW);
  }
  delay(1);
}
