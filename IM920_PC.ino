#include<SoftwareSerial.h>
#include <MsTimer2.h>

SoftwareSerial IM920Serial(8, 9);

char buf[256];
void read_timer()
{
  int i = 0;
  for(int j = 0; j < 256; j++)buf[j] = 0;

  while(Serial.available() > 0)
  {
    buf[i] = Serial.read();
    i++;

    if(i >= 256)
    {
      break;
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  IM920Serial.begin(19200);
  MsTimer2::set(1000, read_timer);
  MsTimer2::start();
}

void loop() {
  // put your main code here, to run repeatedly:
  IM920Serial.println(buf);
}
