#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

SoftwareSerial Esp(3,1);

const char *ssid = "nivellemendiola";  
const char *password = "otendako2";
const char *host = "http://192.168.43.36";  //IP address of server



void setup() {
  Serial.begin(9600);
  Esp.begin(9600);


  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    
  }
}

void loop() {
  

    if(Esp.available())
    {
      char Read = Esp.read();
      Esp.write(Read);
    }
  
  
}
