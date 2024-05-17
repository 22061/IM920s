#include<SoftwareSerial.h>

SoftwareSerial IM920Serial(8, 9);  //RX, TX

char input[30];
int i = 0;  

void setup() {
  Serial.begin(19200);
  IM920Serial.begin(19200);
}

void loop() {
  if (IM920Serial.available()) 
  {
    input[i] = IM920Serial.read();
    if (input[i] == '\n') 
    {
      input[i] = '\n';
      Serial.print(input);
      i = 0;
    }
    else
    {
        i++;
    }
  }
}