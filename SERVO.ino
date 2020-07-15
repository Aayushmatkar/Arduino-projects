#include<Servo.h>
Servo myservo;
int value;
int i;
int j;


void setup() {
  myservo.attach(8);
  

}

void loop() {
  for(i=1;i<10;i++)
  {
    value=i*20;
  myservo.write(value);
  delay(500);
  }
 
  for(j=9;j>0;j--)
  {
   value=j*20;
  myservo.write(value);
  delay(500);
 }
  }
