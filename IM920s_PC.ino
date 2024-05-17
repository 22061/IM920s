#include<ArduinoJson.h>
#include <SoftwareSerial.h>

StaticJsonDocument<200> doc;
SoftwareSerial IM920Serial(8, 9);    // RX, TX

char data[50];

void setup() {
  pinMode(A0, INPUT);        
  pinMode(A1, INPUT);        
  pinMode(5, INPUT_PULLUP);

  Serial.begin(19200);
  IM920Serial.begin(19200);  
}

void loop() {
  int x_pos = map(analogRead(A0), 0, 1023, -1, 1);
  int y_pos = map(analogRead(A1), 0, 1023, -1, 1);
  int sw_pos = digitalRead(5);
  
  doc["x_axis"] = x_pos;
  doc["y_axis"] = y_pos;
  doc["z"] = sw_pos;
  serializeJson(doc, data, 50);

  //Serial.println(data);

  IM920Serial.print("TXDU0002,");
  IM920Serial.println(data);

  delay(1000);
}
