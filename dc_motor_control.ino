const int motorA = 7;
const int motorB = 8;
void setup() {
 pinMode(motorA,OUTPUT);

 pinMode(motorB,OUTPUT);

 digitalWrite(motorA,LOW);
 digitalWrite(motorB,LOW);
 
}

void loop() {
  digitalWrite(motorA,HIGH);
  digitalWrite(motorB,LOW);
  delay(5000);

  digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  delay(5000);
  

}
