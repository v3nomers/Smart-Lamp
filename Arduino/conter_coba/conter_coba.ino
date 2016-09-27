unsigned long time;
int nil,buttonstate,lastbuttonstate;
int buttonstate2,lastbuttonstate2;
long start,stopz;
int fractional;
int hasil;
void setup(){
  Serial.begin(9600);
  pinMode(7,INPUT);
  pinMode(3,OUTPUT);
}
void loop(){
  buttonstate=digitalRead(7);
  buttonstate2=digitalRead(4);
  
  if (buttonstate==1)
  {
    digitalWrite(3,HIGH);
    }
    else if(buttonstate==0)
    {
       digitalWrite(3,LOW);
      }

  
  if (buttonstate2==1 && lastbuttonstate2==0){
//  Serial.print("Time: ");
  start = millis();
  //prints time since program started
//  Serial.println(time);
  // wait a second so as not to send massive amounts of data
//  delay(1000);
  lastbuttonstate2=buttonstate2; 
  }
  else if(buttonstate2==0 && lastbuttonstate2==1)
  {
    stopz=millis()-start;
    hasil=stopz/1000;
    lastbuttonstate2=buttonstate2;
    Serial.println(hasil);
   
    }
else{
  lastbuttonstate2=buttonstate2;
 
  }
  
}
