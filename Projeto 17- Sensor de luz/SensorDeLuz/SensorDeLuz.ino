int piezoPin =8;  //Piezo no pino 8
int ldrPin=0;     //LDR no pino analogico 0
int ldrValue= 0;  //valor lido do LDR

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  ldrValue = analogRead(ldrPin);  //le o valor do LDR
  tone(piezoPin, 50);           //toca um tom de 1000hz do piezo
  delay(25);                     //espero um pouco 
  noTone(piezoPin);              //interompe o tom
  delay(ldrValue);               //espera a quantidade de mulissegundos em ldrValuer
}
