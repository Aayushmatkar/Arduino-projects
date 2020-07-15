void setup() 
{
pinMode(10,INPUT_PULLUP);    //A
pinMode(11,INPUT_PULLUP);    //B
Serial.begin(9600);
}

void loop()
{
  if(digitalRead(10)==LOW)
  {
  Serial.println("switch A pressed");
  }
  delay(100);

     if(digitalRead(11)==LOW)
     {
     Serial.println("switch B pressed");
     }
     delay(100); 

}
