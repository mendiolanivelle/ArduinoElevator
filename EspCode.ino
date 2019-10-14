#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

SoftwareSerial Esp(3,1);
void setup() {
  Serial.begin(9600);
  Esp.begin(9600);

}

void loop() {
  

    if(Esp.available())
    {
      char Read = Esp.read();
      Esp.write(Read);
    }
  
  
}
