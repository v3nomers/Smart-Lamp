int a,b,c;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  a=200;
  b=300;
  c=278;
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("#" + String(a)+ "$" + String(b)+"@"+String(c)+"*");
delay(1000);
}
