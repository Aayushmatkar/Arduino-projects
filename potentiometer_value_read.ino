void setup() {
 pinMode(A1,INPUT);
 Serial.begin(9600);
 int s;
  int a=map (s,0,1023 ,0,10000);
}

void loop() {
 
  int s=analogRead(A1);
  delay(1000);
 
    int a=map (s,0,1023 ,0,10000); //FOR RESISTANCE
Serial.println(a);
}
