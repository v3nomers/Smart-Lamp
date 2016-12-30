/*
 *  This sketch sends data via HTTP GET requests to data.sparkfun.com service.
 *
 *  You need to get streamId and privateKey at data.sparkfun.com and paste them
 *  below. Or just customize this script to talk to other HTTP servers.
 *
 */
//?20$30@22%52&65!
float hasil_terima;
String data_lama,data_baru;
String data_lama2,data_baru2;
unsigned int datake = 0;
String data1, data2, data3,data4,data5,data6;
String data11, data22, data33,data44,data55;
String Irms,PIR,Vrms,PF,Daya,lampu;
float Hasil_PIR,Hasil_Irms,Hasil_Vrms,Hasil_PF,Hasil_Daya,Hasil_lampu;
unsigned long previousMillis = 0; 
 String terima,terima2;
    char charIn;
    int berhenti;
unsigned long currentMillis ;
unsigned long  interval=5000;


int terima_PIR;
long currentMillis2 ;
unsigned long  interval2=30000;
unsigned long previousMillis2 = 0; 


unsigned long currentMillis3;
unsigned long  interval3=15000;
unsigned long previousMillis3 = 0; 


unsigned long currentMillis4;
unsigned long  interval4=100000;
unsigned long previousMillis4 = 0; 

int value=1;


#include <ESP8266WiFi.h>

const char* ssid     = "Thoem_us";
const char* password = "88888888";
String writeAPIKey = "WD38811PP85WRV94";
String apiKey = "WD38811PP85WRV94";
String channelID = "149570";

const char* host = "smart-lamp.pe.hu";
const char* server = "api.thingspeak.com";
String lastCommand = "wew";
 int nilai1=1;
  int nilai2=0;


  //////////////////////
  /// update dari web///
  //////////////////////



void update_lampu_web(){

//if (Client.available() > 0)
 String url = "/lampu.php?";
WiFiClient Client;
const int httpPort = 80;
  if (!Client.connect(host, httpPort)) {
    Serial.println("Connection failed");
    return;
  }
Client.print(String("GET ") + url  + "&headers=false" + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
 delay(30);


    if(Client.available() > 0){
//      String line = Client.readStringUntil('!');
    do{
      charIn = Client.read(); // read a char from the buffer
      terima2 += charIn; // append that char to the string response
       terima2.trim();
       if(terima2.endsWith("Type:application/json")){
    terima2="";
     
    
previousMillis = currentMillis;
    }
    }
 
 
 
while(Client.available()>0 );

 Serial.println(terima2); 
 hasil_terima= terima2.toInt(); 
 
   
if(hasil_terima>42000 && berhenti==0){
  previousMillis4 = currentMillis4;
  berhenti=1;
  } 
if(hasil_terima>42000  ){
  if ((currentMillis4 - previousMillis4) < interval4) {  
     Serial.println("ON");
     digitalWrite(4,HIGH);
     berhenti=2;
  }
  else{
    digitalWrite(4,LOW);  
    Serial.println("OFF");
    } 
}
  if (hasil_terima<42000&&berhenti==2)
 {
  berhenti=0;
   digitalWrite(4,LOW);  
  }  

    }
}  




void setup() {
   pinMode(14, INPUT);
  pinMode(4,OUTPUT);
 
  Serial.begin(9600);
 

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(10);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}



void serial_parse(){
  
  
if (Serial.available() > 0)
  {
    char terima = Serial.read();
    switch (terima) {
      case '?':
        datake = 1;
        break;

      case '$':
        datake = 2;
        break;

      case '@':
        datake = 3;
        break;
        
      case '%':
        datake=4;
        break;
        
        case '&':
        datake=5;
        break;

        case '#':
        datake=6;
        break;

      case '!':
        PIR = data1;
        Irms = data2;
        Vrms = data3;
        PF   = data4;
        Daya = data5;
        lampu = data6;
        
        data1 = "";
        data2 = "";
        data3 = "";
        data4 = "";
        data5 = "";
        data6 = "";  
        
        datake = 0;
        break;

      default:
        switch (datake) {
          case 1:
            data1 += terima;
            break;

          case 2:

            data2 += terima;
            break;

          case 3:

            data3 += terima;
            break;
          
          case 4:
            data4 += terima;
            break;

          case 5:
            data5 += terima;
            break;

            case 6:
            data6 += terima;
            break;

          default:
            // if nothing else matches, do the default
            // default is optional
            break;
        }
        break;
    }
    
  }

data_lama=Daya;

  Serial.println("PIR=" + PIR + " | " + "Arus=" + Irms + " | " + "Volt=" + Vrms + " | " + "PF=" + PF + " | " + "daya=" + Daya + " | "+ "lampu=" +lampu );
  Hasil_lampu=(lampu.toFloat());
  Hasil_PIR=(PIR.toFloat());
  Hasil_Irms=(Irms.toFloat());
  Hasil_Vrms=(Vrms.toFloat());
  Hasil_PF=(PF.toFloat());
  Hasil_Daya=(Daya.toFloat());   
Serial.flush() ;




  
}




void update_web(){

Serial.print("Connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient Client;
  const int httpPort = 80;
  if (!Client.connect(host, httpPort)) {
    Serial.println("Connection failed");
    return;
  }
  
  // We now create a URI for the request
  String url = "/upload.php?Daya=";
  String con_tegangan = "&Tegangan=";
  String con_Arus = "&Arus=";
  String con_PF = "&PF=";
  String con_PIR = "&PIR=";
  Serial.print("Requesting URL: ");
  Serial.println(host + url + Daya + con_tegangan + Vrms + con_Arus + Irms + con_PF + PF + con_PIR + PIR  );
  Serial.println(String("TRY: ") + value );
  
  // This will send the request to the server
 Client.print(String("GET ") + url + Daya + "&Tegangan=" + Vrms  + "&Arus=" + Irms + "&PF=" + PF + "&PIR="+ PIR   +"&headers=false" + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  delay(30);
  
  // Read all the lines of the reply from server and print them to Serial
  while(Client.available()){
  String line = Client.readStringUntil('\r');
  Serial.println(line);
  
 }
  Serial.println("");
  Serial.println(String("Try nr. ") + value + " is finished.");
  Serial.println("Waiting for next try...");
  Serial.println("");
  value = value + 1;
  
previousMillis2 = currentMillis2; 
}

void update_lampu(){
int terima_PIR = analogRead(A0);
Serial.println(terima_PIR);
Serial.print("Connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient Client;
  const int httpPort = 80;
  if (!Client.connect(host, httpPort)) {
    Serial.println("Connection failed");
    return;
  }
  
  // We now create a URI for the request
  String url = "/upload_PIR.php?&lampu=";

  Serial.print("Requesting URL: ");
  Serial.println(host + url + terima_PIR );
  Serial.println(String("TRY: ") + value );
  
  // This will send the request to the server
 Client.print(String("GET ") + url + terima_PIR   +"&headers=false" + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  delay(30);
  
  // Read all the lines of the reply from server and print them to Serial
  while(Client.available()){
  String line2 = Client.readStringUntil('\r');
  Serial.println(line2);
  
 }
  Serial.println("");
  Serial.println(String("Try nr. ") + value + " is finished.");
  Serial.println("Waiting for next try...");
  Serial.println("");
  value = value + 1;
  
previousMillis3 = currentMillis3; 
}


void loop() {
   
 currentMillis4 = millis();    
//  Serial.println(berhenti);
serial_parse();

if(data_lama!=data_baru){ 
currentMillis2  = millis();
while (currentMillis2 - previousMillis2 >= interval2) {  
update_web();
data_lama=data_baru;
break;
}
}


currentMillis3  = millis();
while (currentMillis3 - previousMillis3 >= interval3) {  
update_lampu();
break;
}



currentMillis  = millis();
while (currentMillis - previousMillis >= interval) {  
update_lampu_web();
break;

}







 }

