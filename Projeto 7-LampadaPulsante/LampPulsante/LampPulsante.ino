
  byte ledPin[]={4,5,6,7,8,9,10,11,12,13};
  float sinVal;
  int ledVal;
  
void setup() {
 pinMode(ledPin[5], OUTPUT);
}

void loop() {
  for (int x=0; x<180;x++){
    sinVal= (sin(x*(3.1416/180)));
    ledVal=int(sinVal*255);
    analogWrite(ledPin[5], ledVal);
    delay(55);
  }
}
