
int LDR=0;
void setup() {
 Serial.begin(9600);
 pinMode(A1,INPUT);
 pinMode(13,OUTPUT);
 

}

void loop() {
LDR=analogRead(A1);
Serial.print("Analog read value=");
Serial.println(LDR);
delay(10);
{
if 
  (LDR<=750)
  {
   digitalWrite(13,HIGH);
  }
else{
  digitalWrite(13,LOW);
}
}
}
