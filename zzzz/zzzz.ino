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
 int nilai1=1;
  int nilai2=0;
void setup() {
   pinMode(14, INPUT);
  pinMode(4,OUTPUT);
 
  Serial.begin(115200);
  delay(100);
  
  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

int value = 0;

void loop() {
  
  ++value;

   WiFiClient client;
  const int httpPort = 80;
  
  int baca_data=digitalRead(14);
 if (lastCommand=="red")
 {
  digitalWrite(4,HIGH);
       if (client.connect(host,80)) {  // connects to thingspeak & sends the value of (pir)
        String postStr = apiKey;
               postStr +="command_string=2&position=1"; 
               postStr += "\r\n\r\n";  
         client.print("POST /update HTTP/1.1\n"); 
         client.print("Host: api.thingspeak.com\n"); 
         client.print("Connection: close\n"); 
         client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n"); 
         client.print("Content-Type: application/x-www-form-urlencoded\n"); 
         client.print("Content-Length: "); 
         client.print(postStr.length()); 
         client.print("\n\n"); 
         client.print(postStr);
       }
  }
  if (lastCommand=="blue")
 {
  digitalWrite(4,LOW);
   if (client.connect(host,80)) {  // connects to thingspeak & sends the value of (pir)
        String postStr = apiKey;
               postStr +="&field1="; 
               postStr += String(nilai2); 
               postStr += "\r\n\r\n";  
         client.print("POST /update HTTP/1.1\n"); 
         client.print("Host: api.thingspeak.com\n"); 
         client.print("Connection: close\n"); 
         client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n"); 
         client.print("Content-Type: application/x-www-form-urlencoded\n"); 
         client.print("Content-Length: "); 
         client.print(postStr.length()); 
         client.print("\n\n"); 
         client.print(postStr);
   }
  }


  
  Serial.print(lastCommand);
  Serial.print("\nconnecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
 
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  /////////////////////////////////////////////////
  
//   String url = "/update?key=";
//  url+=writeAPIKey;
//  url+="&field1=";
//  url+=String(baca_data);
//  
//  
//  // Request to the server
//  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
//               "Host: " + host + "\r\n" + 
//               "Connection: close\r\n\r\n");
//    delay(1000);
    ///////////////////////////////////////////////////////////
  // We now create a URI for the request
  String url2 = "https://api.thingspeak.com/talkbacks/10087/commands/execute?api_key=94FROOTO95KLMJ2E";
//  url += streamId;
//  url += "?private_key=";
//  url += privateKey;
//  url += "&value=";
//  url += value;
//  
  Serial.print("Requesting URL: ");
  Serial.println(url2);
  
  // This will send the request to the server
  client.print(String("GET ") + url2 + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()>0){
//    String line = client.readStringUntil('\r');
//    Serial.print(line);
    delay(100);
    String response;
    char charIn;
    do {
     
      charIn = client.read(); // read a char from the buffer
   
      response += charIn; // append that char to the string response
    }
    while (client.available() > 0);
 Serial.print(charIn); 
  if (charIn == 'l')
    {
      lastCommand = "red";
  }
   if (charIn == '2')
    {
      lastCommand = "blue";
  }
    // Send matching commands to LEDs
    }
   
  Serial.println();
  Serial.println("closing connection");

 }
