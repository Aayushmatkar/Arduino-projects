void setup() {
 pinMode(A1,INPUT);
 Serial.begin(9600);

}

void loop() {
  int x;
  x= analogRead(A1);
  Serial.println(x);
  delay(1000);
  

}
