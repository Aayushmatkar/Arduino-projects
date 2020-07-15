void setup() {
 pinMode(5,INPUT);
 pinMode(13,OUTPUT);
 pinMode(8,OUTPUT);
 Serial.begin(9600);
}

void loop() {
 
 if(digitalRead(5)==HIGH)
  {
     Serial.println("light is off AND ALARM ACTIVATED");
 
 digitalWrite(13,LOW);
  tone(8,1200);
  digitalWrite(4,HIGH);
  delay(1000);
  digitalWrite(4,LOW);
  noTone(8);
 delay(1000);
  }
else 
{
  Serial.println("light is onn");
 
  digitalWrite(13,HIGH);
  noTone(8);
 digitalWrite(8,LOW);
 delay(100);
  
}

}
