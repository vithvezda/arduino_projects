int leftbut=3;
int rightbut=2;
int counter=0;

int ledarr [5][5]={
  {1,0,0,0,0},
  {0,1,0,0,0},
  {0,0,1,0,0},
  {0,0,0,1,0},
  {0,0,0,0,1},
};
int leds[]={8,9,10,11,12};
void setup() {
  // put your setup code here, to run once:
  pinMode(1,INPUT);
  pinMode(2,INPUT);
  for(int i=0;i<=4;i++){
    pinMode(leds[i],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(leftbut)==HIGH){
    counter--;
    delay(200);
  }
  if(digitalRead(rightbut)==HIGH){
    counter++;
    delay(200);
  }
  if(counter==-1){
    counter=4;
  }
  if(counter==5){
    counter=0;
  }
  for(int j=0;j<=5;j++){
    digitalWrite(leds[j],ledarr[j][counter]);
  }
}
