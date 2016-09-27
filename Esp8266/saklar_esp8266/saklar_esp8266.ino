#include <ESP8266WiFi.h>
 
const char* ssid     = "Keluarga Subekti";
const char* password = "keluargasubekti";
 
const char* host = "api.thingspeak.com";
 
int value = 1; 
 
void setup() {
  Serial.begin(115200);
  delay(10);
   pinMode(14, INPUT);
   pinMode(12, INPUT);
 
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
  
}//end setup
  
void loop() {  
  delay(500);
  
  int button1= digitalRead(14);
  int button2= digitalRead(12);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient Client;
  const int httpPort = 80;
    if (!Client.connect(host, httpPort)) {
    return;
  }
  
 if (button1==1){
 String url1 = "/apps/thinghttp/send_request?api_key=BKRG0GE964TJRAXI";
 Client.print(String("GET ") + url1 + "&headers=false" + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  delay(500);}
  if (button2==1){
 String url2 = "/apps/thinghttp/send_request?api_key=COA52U9U4KFT6CMS";
 Client.print(String("GET ") + url2 + "&headers=false" + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  delay(500);}
  
  // Read all the lines of the reply from server and print them to Serial
  }
