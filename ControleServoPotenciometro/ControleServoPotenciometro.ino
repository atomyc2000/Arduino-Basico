#include <Servo.h>

#define pinServo 8
#define pinPotenciomentro A0

Servo servo1;

void setup() {
  servo1.attach(pinServo);
  Serial.begin(9600);

}

void loop() {
  int lido = analogRead(pinPotenciomentro);
  byte angulo = map( lido, 0, 1023, 0, 179);  //transforma valor lido do potenciometro (0,1023) em angulo (0,179)

  servo1.write(angulo);

  //visualização do valores na tela
  Serial.print("A0:");
  Serial.print(lido);
  Serial.print("angulo:");
  Serial.print(angulo);

}
