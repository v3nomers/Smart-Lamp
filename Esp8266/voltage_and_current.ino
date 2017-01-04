// EmonLibrary examples openenergymonitor.org, Licence GNU GPL V3

#include "EmonLib.h"             // Include Emon Library
EnergyMonitor emon1;             // Create an instance

int PIR;
int Euler = 2.718281828459045235360287471352;
float daya_lama,daya_baru,daya_tampil;
float PIR_lama,PIR_baru,PIR_tampil;
float V_lama,V_baru,V_tampil;
float I_lama,I_baru,I_tampil;
float PF_lama,PF_baru,PF_tampil;
float lampu_lama,lampu_baru,lampu_tampil;
int lampu;

unsigned long previousMillis = 0; 
const long interval = 10000;
unsigned long currentMillis;

unsigned long currentMillis2=10000 ;
unsigned long  interval2=10000;
unsigned long previousMillis2 = 0; 

int value,a,b,c;
float Irms,supplyVoltage,powerFActor;
void setup()
{
  
  Serial.begin(9600);
  emon1.voltage(3, 101, 1.4);  // Voltage: input pin, calibration, phase_shift
  emon1.current(2, 17);      // Current: input pin, calibration.
  pinMode(3,OUTPUT);
 currentMillis  = millis();
};
void sensorpir(){
   currentMillis2 = millis()+10000;
  PIR  = analogRead(A0);
 if(PIR>300){
  previousMillis2 = currentMillis2;
  } 
if (currentMillis2 - previousMillis2 < interval2) {  

digitalWrite(3,HIGH);
 } 
if (currentMillis2 - previousMillis2 > interval2) {  

digitalWrite(3,LOW);
 } 
 
  }

  
void hitung()
{ 
  a++;
  value++;
//  Serial.print(value);
//  Serial.print("==");
//  Serial.print(a);
//  Serial.print("==");
//  Serial.print(b);
//  Serial.print("==");
  
  
  
   emon1.calcVI(20, 5000);        // Calculate all. No.of half wavelengths (crossings), time-out
  // Print out all variables (realpower, apparent power, Vrms, Irms, power factor)
 
  float realPower       = abs(emon1.realPower);        //extract Real Power into variable
  float apparentPower   = emon1.apparentPower;    //extract Apparent Power into variable
  float powerFActor     = abs (emon1.powerFactor);      //extract Power Factor into Variable
  float supplyVoltage   = emon1.Vrms;             //extract Vrms into Variable
  float Irms            = emon1.Irms;             //extract Irms into Variable
if(a>2){
  daya_lama=realPower/3600;
  daya_baru=daya_lama+daya_baru;
  
  lampu_lama=lampu;
  lampu_baru=lampu_lama;
  
   PIR_lama=PIR;
   PIR_baru=PIR_lama;

   V_lama=supplyVoltage;
   V_baru=V_lama+V_baru;

   I_lama=Irms;
   I_baru=((-26.908*(pow(I_lama,4)))+(20.571*(pow(I_lama,3)))-(8.269*((pow(I_lama,4))))+(1.1945*I_lama)+I_baru);
  
  
  PF_lama=powerFActor ;
  PF_baru=((26.697*(pow(PF_lama,4)))-(81.875*(pow(PF_lama,3)))+(99.927*(pow(PF_lama,2)))-(52.852*PF_lama)+(10.755)+PF_baru);
  if(PF_baru>0.75&&PF_baru<0.90)
  {
    PF_baru=PF_baru-0.15;
    
    }
 if(PF_baru>0.90&&PF_baru<1)
 {
  PF_baru=PF_baru+0.05;
  }
 if(PF_baru<75)
 {
  PF_baru=PF_baru-0.07;
  
  
  }
  }
//Serial.print("^^^^^^^^^^");
//  Serial.print('?');
//  Serial.print(PIR);
//  Serial.print('$');
//  Serial.print(Irms);
//  Serial.print('@');
//  Serial.print(supplyVoltage);
//  Serial.print('%');
//  Serial.print(powerFActor);
//  Serial.print('&');
//  Serial.print(realPower);
//  Serial.println('!');

//Serial.print("^^^^^^^^^^");
//  Serial.print('?');
//  Serial.print(PIR_baru);
//  Serial.print('$');
//  Serial.print(I_baru);
//  Serial.print('@');
//  Serial.print(V_baru);
//  Serial.print('%');
//  Serial.print(PF_baru);
//  Serial.print('&');
//  Serial.print(daya_baru);
//  Serial.println('!');
//  Serial.println(value);
//  Serial.println(a);
//  Serial.println(b);
  
}
void loop()
{ 
    sensorpir();
//Serial.println(PIR);
  lampu=analogRead(A0); 
  currentMillis  = millis();
   if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
      previousMillis = currentMillis;
//   Serial.print("currentMillis:");
//   Serial.println(currentMillis2);
//   Serial.print("previousMillis");
//   Serial.println(previousMillis2);
//Serial.print("value=");
//Serial.println(value);
//Serial.print("a=");
//Serial.println(a);
//Serial.print("b=");
//Serial.println(value);


 hitung(); 
 
  if (value>=2 &a>1){
    value=0;
        b++;
        
  Serial.print('?');
  Serial.print(PIR_tampil);
  Serial.print('$');
  Serial.print(I_tampil);
  Serial.print('@');
  Serial.print(V_tampil);
  Serial.print('%');
  Serial.print(PF_tampil);
  Serial.print('&');
  Serial.print(daya_tampil);
  Serial.print('#');
  Serial.print(lampu_tampil);
  Serial.println('!');

  
//?20$30@22%52&65!
if(b>0){
  daya_tampil=daya_baru;
  V_tampil=V_baru/60;
  I_tampil=I_baru/60;
  PF_tampil=PF_baru/60;
  PIR_tampil=PIR_baru;
  lampu_tampil=lampu_baru;


if (PF_tampil>0.90 && PF_tampil<1)
{
  PF_tampil=PF_tampil+0.07;
}
if (PF_tampil>1&& PF_tampil<=2)
{
  PF_tampil=1;
  
  }
  if (PF_tampil>2)
  {
    PF_tampil=0;
    }

  
  }
//  V_tampil=V_baru;
//  I_tampil=I_baru;
//  PIR_tampil=PIR_baru;
//  PF_tampil=PF_baru;
  
//  Serial.println(daya_tampil);

V_baru=0;
I_baru=0;
PF_baru=0;


  }
   }

 

}

