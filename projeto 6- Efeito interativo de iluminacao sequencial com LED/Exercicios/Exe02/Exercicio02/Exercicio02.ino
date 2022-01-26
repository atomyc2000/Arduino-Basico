
  byte ledPin[]={4,5,6,7,8,9,10,11,12,13};
  int ledDelay(90);
  int direction =1;
  int currentLED=0;
  unsigned long changeTime;
  int potPin = 2;
  
void setup() {
  for (int x=10; x>0; x=x-1){
    for(int y=0; y<x; y++){
      pinMode(ledPin[y], OUTPUT);
      changeTime = millis();
    }
  }
}

void loop() {
  //ledDelay = analogRead(potPin);
  if ((millis() - changeTime) > ledDelay){
    changeLED();
    changeTime = millis();
  }
}

void changeLED(){
  for (int x=10; x>0; x=x-1){
      digitalWrite(ledPin[x], LOW);
  }
    digitalWrite(ledPin[currentLED], HIGH);
    currentLED += direction;

    if(currentLED==9) {direction =-1;}
    if(currentLED==0) {direction = 1;}

}
