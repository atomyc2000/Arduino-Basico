
  char buffer[18];
  int vermelho, verde, azul;
  int vermelhoPin = 12;
  int verdePin = 13;
  int azulPin= 11;
   
void setup() {
  Serial.begin(9600);
  Serial.flush();
  pinMode(vermelhoPin, OUTPUT);
  pinMode(verdePin, OUTPUT);
  pinMode(azulPin, OUTPUT);
}

void loop() {
    if (Serial.available() > 0) {
      int index=0;
      delay(100); // deixe o buffer encher
      int numChar = Serial.available();
      if (numChar>15) {
        numChar=15;
      }
      while (numChar--) {
        buffer[index++] = Serial.read();
      }
      splitString(buffer);
      }
}

void splitString(char* data) {
    Serial.print("Data entered: ");
    Serial.println(data);
    char* parameter;
    parameter = strtok (data, " ,");
    while (parameter != NULL) {
      setLED(parameter);
      parameter = strtok (NULL, " ,");
    }
    // Limpa o texto e os buffers seriais
    for (int x=0; x<16; x++) {
      buffer[x]='\0';
    }
    Serial.flush();
}

void setLED(char* data) {
    if ((data[0] == 'r') || (data[0] == 'R')) {
      int Ans = strtol(data+1, NULL, 10);
      Ans = constrain(Ans,0,255);
      analogWrite(vermelhoPin, Ans);
      Serial.print("o vermelho deve ser: ");
      Serial.println(Ans);
    }
    if ((data[0] == 'g') || (data[0] == 'G')) {
      int Ans = strtol(data+1, NULL, 10);
      Ans = constrain(Ans,0,255);
      analogWrite(verdePin, Ans);
      Serial.print("O verde deve ser: ");
      Serial.println(Ans);
    }
    if ((data[0] == 'b') || (data[0] == 'B')) {
      int Ans = strtol(data+1, NULL, 10);
      Ans = constrain(Ans,0,255);
      analogWrite(azulPin, Ans);
      Serial.print("O azul deve ser: ");
      Serial.println(Ans);
    }
}
