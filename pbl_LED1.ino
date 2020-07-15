void setup() {
 pinMode(11,OUTPUT);

}

void loop() {
 digitalWrite(12,HIGH);
 delay(1000);

 digitalWrite(12,LOW);
 delay(1000);
 digitalWrite(11,HIGH);
 delay(3000);
 digitalWrite(11,LOW);
 delay(1000);
}
