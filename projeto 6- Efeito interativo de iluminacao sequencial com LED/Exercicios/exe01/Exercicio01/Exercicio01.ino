
  byte ledPin[]={4,5,6,7,8,9,10,11,12,13};
  int ledDelay(50);
  int direction =1;
  int currentLED=0;
  int invertLED=9;
  int inverte=-1;
  unsigned long changeTime;
  int potPin = 2;
  
void setup() {
  for (int x=0; x<10; x++){
    pinMode(ledPin[x], OUTPUT);
    changeTime = millis();
  }
  for (int y=10; y>0; y=y-1){
    pinMode(ledPin[y], OUTPUT);
    changeTime = millis();
  }
}

void loop() {
  ledDelay = analogRead(potPin);
  if ((millis() - changeTime) > ledDelay){
    changeLED();
    changeTime = millis();
  }
}

void changeLED(){
  for (int x=0; x<10; x++){
    digitalWrite(ledPin[x], LOW);
  }
  for (int y=10; y>0; y=y-1){
    digitalWrite(ledPin[y], LOW);
  }
  digitalWrite(ledPin[currentLED], HIGH);
  currentLED += direction;

  if(currentLED==9) {direction =-1;}
  if(currentLED==0) {direction = 1;}
  //sentido contrario
  digitalWrite(ledPin[invertLED], HIGH);
  invertLED += inverte;

  if(invertLED==9) {inverte =-1;}
  if(invertLED==0) {inverte =1;}
}
