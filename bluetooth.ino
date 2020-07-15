char inByte;
const int LED1=12;
const int LED2=11;


void setup()
{Serial.begin(9600);
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);

digitalWrite(LED1,LOW);
digitalWrite(LED2,LOW);

 

}

void loop() 
{char inByte;
if(Serial.available()>0);
{ inByte=Serial.read();
switch (inByte){
  case 'A' :digitalWrite(LED1,HIGH);break;
  case 'a' :digitalWrite(LED1,LOW);break;
  case 'B' :digitalWrite(LED2,HIGH);break;
  case 'b' :digitalWrite(LED2,LOW);break; 
}
}
delay(1000);

 

}
