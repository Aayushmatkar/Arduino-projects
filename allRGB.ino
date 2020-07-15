int i;
int j;
int k;

void setup()  
{
 pinMode(11,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(9,OUTPUT);
}

void loop() {
  for(i=0;i<255;i++)
  {
    analogWrite(11,i);
    delay(10);
  }
  for(j=0;j<255;j++)
  {
    analogWrite(10,j);
    delay(10);
  }
  for(k=0;k<255;k++)
  {
    analogWrite(9,k);
    delay(10);
  }
}
