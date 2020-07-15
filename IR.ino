void setup() {
 pinMode(A1,INPUT);
 pinMode(13,OUTPUT);

 Serial.begin(9600);
 
}

void loop() {
  if(digitalRead(A1)==LOW)
  {
    int i=0 ;
   i++;
    Serial.println("obstacle detected");
    delay(1000);
    Serial.println(i);
    digitalWrite(13,HIGH);
    delay(1000);
    
  }
  else
  {
    Serial.println("ALL CLEAR ");
    digitalWrite(13,LOW);
     delay(1000);
  }
 
}
