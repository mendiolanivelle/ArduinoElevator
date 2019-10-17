#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <SoftwareSerial.h>

#include <DHT.h>
#include <Adafruit_Sensor.h>

#define DHTPIN D1
#define DHTTYPE DHT11 

#include "SH1106Wire.h"
 
//ESP Web Server Library to host a web page
#include <ESP8266WebServer.h>

#include <Wire.h>
 #include "index.h" //Our HTML webpage contents

 SH1106Wire display(0x3c, D2, D3);
//---------------------------------------------------------------
//Our HTML webpage contents in program memory
const char* host = "192.168.1.20";
DHT dht(DHTPIN, DHTTYPE);
//---------------------------------------------------------------
//On board LED Connected to GPIO2
int data = 50;
int data1 = 51;
int data2 = 52;
int data3 = 53;
int data4 = 54;
int data5 = 55;
int data6 = 56;
int data7 = 57;
int data8 = 58;
int data9 = 59;



  
 
//SSID and Password of your WiFi router
const char* ssid = "nivellemendiola";
const char* password = "otendako2";
 
//Declare a global object variable from the ESP8266WebServer class.
ESP8266WebServer server(80); //Server on port 80
 
//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 Serial.println("You called root page");
 String sm = MAIN_page; //Read HTML contents
 server.send(200, "text/html", sm); //Send web page
}
 
void handleLEDon1() { 

 Serial.println(data);
 server.send(200, "text/html", "You Pressed Ground Floor"); //Send web page


}

void handleLEDon2() { 

 Serial.println(data1);
 server.send(200, "text/html", "You Pressed Second Floor Down"); //Send web page
 

}

void handleLEDon3() { 

 Serial.println(data2);
 server.send(200, "text/html", "You Pressed Second Floor Up"); //Send web page


}

void handleLEDon4() { 

Serial.println(data3);
server.send(200, "text/html", "You Pressed Third Floor Down"); //Send web page

}

void handleLEDon5() { 

Serial.println(data4);
server.send(200, "text/html", "You Pressed Third Floor Up"); //Send web page
}

 void handleLEDon6() { 

 
 Serial.println(data5);
 server.send(200, "text/html", "You Pressed Forth Floor"); //Send web page

}

void handleLEDon7() { 

 Serial.println(data6);
 server.send(200, "text/html", "You Pressed First Floor"); //Send web page
  

}

void handleLEDon8() { 

Serial.println(data7);
server.send(200, "text/html", "You Pressed Second Floor"); //Send web page

}

void handleLEDon9() { 

Serial.println(data8);
server.send(200, "text/html", "You Pressed Third Floor"); //Send web page
 
}

void handleLEDon10() { 

Serial.println(data9);
server.send(200, "text/html", "You Pressed Forth Floor"); //Send web page
 
}

//==============================================================
//                  SETUP
//==============================================================
void setup(){
  Serial.begin(115200);
 
   display.init();

  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setFont(ArialMT_Plain_16);
  display.drawString(64, 0, "IOT based");
  display.drawString(64, 20, "Elevator");
  display.display();
  delay(5000);
  display.clear();
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");
 
  //Onboard LED port Direction output
  
  
  // Wait for connection
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    
    Serial.print(".");
  }
 
  //If connection successful show IP address in s monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
 
  server.on("/", handleRoot);      //Which routine to handle at root location. This is display page
  server.on("/gpio/10", handleLEDon1); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/gpio/11", handleLEDon2); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/gpio/12", handleLEDon3); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/gpio/13", handleLEDon4); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/gpio/14", handleLEDon5); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/gpio/15", handleLEDon6); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/gpio/16", handleLEDon7); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/gpio/17", handleLEDon8); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/gpio/18", handleLEDon9); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/gpio/19", handleLEDon10); //as Per  <a href="ledOn">, Subroutine to be called
  
 
  server.begin();                  //Start server
  Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop(){
  server.handleClient();    //Handle client requests

  }
