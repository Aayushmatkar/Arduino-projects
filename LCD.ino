#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
               //    RS,EN,D4,D5,D6,D7
int i=0;

void setup() {
 lcd.begin(16,2);
 pinMode(9,INPUT);
Serial.begin(9600);
}

void loop() {
  if(digitalRead(9)==HIGH)
  {
  lcd.clear();
  lcd.print("motion detected");
  Serial.println("motion detected");
delay(1000);
  }
  else{
    lcd.clear();
    lcd.print("no motion");
  }
  }
