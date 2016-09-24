//#123$456@789*
unsigned int datake=0;
String data1,data2,data3;
String data11,data22,data33;
void setup() {
  Serial.begin(57600);
}

void loop() {
  if (Serial.available()>0)
  {
    char terima = Serial.read();
    switch (terima) {
    case '#':
    datake=1;
    break;
    
    case '$':
    datake=2;
    break;
    
    case '@':
    datake=3;
    break;

    case '*':
    data11=data1;
    data22=data2;
    data33=data3;

    data1="";
    data2="";
    data3="";
    
    datake=0;
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

       
    default: 
      // if nothing else matches, do the default
      // default is optional
    break;
  }
    break;
    }
  }


  Serial.println("Data1=" + data11 + " | " + "Data2=" + data22 + " | " + "Data3=" + data33 );
}
