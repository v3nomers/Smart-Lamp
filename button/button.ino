/*
 *  This sketch sends data via HTTP GET requests to data.sparkfun.com service.
 *
 *  You need to get streamId and privateKey at data.sparkfun.com and paste them
 *  below. Or just customize this script to talk to other HTTP servers.
 *
 */

#include <ESP8266WiFi.h>

const char* ssid     = "Keluarga Subekti";
const char* password = "keluargasubekti";
String writeAPIKey = "WD38811PP85WRV94";
String apiKey = "WD38811PP85WRV94";
String channelID = "149570";

const char* host = "api.thingspeak.com";
const char* server = "api.thingspeak.com";
String lastCommand = "wew";
  int button2;
  int button1;
  
int old_something;
void setup() {
   pinMode(14,INPUT);
   pinMode(4,INPUT);
 button1=digitalRead(4);
 button2=digitalRead(14);
Serial.begin(9600);
delay(100);
//  
//  // We start by connecting to a WiFi network
//
//  Serial.println();
//  Serial.println();
//  Serial.print("Connecting to ");
//  Serial.println(ssid);
//  



}

void loop() {
//   WiFiClient client;
//  const int httpPort = 80;

 int something = (button1);
 if (something != old_something)
   Serial.print (something);  // display if it changed
   old_something = something;
 



  

}
  
  
