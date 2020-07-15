#include<MFRC522.h>
#include<LiquidCrystal.h>
#include<SPI.h>
#include<Servo.h>

#define rs 2
#define en 3
#define d4 4
#define d5 5
#define d6 6
#define d7 7

MFRC522 mfrc522(10,9);
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
Servo myservo;

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  lcd.begin(16,2);
  myservo.attach(8);
  myservo.write(170);
  lcd.print("#ACCESS CONTROL#");
  lcd.setCursor(0,1);
  lcd.print("    Scan Tag");
  mfrc522.PCD_Init();
  Serial.println("Scan Tag");
}

void loop()
{
  if(!mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  if(!mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  String uid="";
  Serial.println();
  Serial.print("UID=");
  for(int i=0;i<mfrc522.uid.size;i++)
  {
    Serial.print(mfrc522.uid.uidByte[i]<0x10 ? "0" : "");
    Serial.print(mfrc522.uid.uidByte[i],HEX);
    uid.concat(String(mfrc522.uid.uidByte[i]<0x10 ? "0" : ""));
    uid.concat(String(mfrc522.uid.uidByte[i],HEX));
  }
  uid.toUpperCase();
  if(uid=="9BCB0C99")
  {
    Serial.print(":Dwij Patel");
    lcd.clear();
    lcd.print(" ACCESS GRANTED");
    lcd.setCursor(0,1);
    lcd.print("  Dwij Patel");
    myservo.write(10);
  }
  else if(uid=="D0693C1B")
  {
    Serial.print(":Paarth");
    lcd.clear();
    lcd.print(" ACCESS DENIED");
    lcd.setCursor(0,1);
    lcd.print("     Paarth");
    myservo.write(170);
  }
  else if(uid=="6B42EB66")
  {
    Serial.print(":Maneen");
    lcd.clear();
    lcd.print(" ACCESS DENIED");
    lcd.setCursor(0,1);
    lcd.print("     Maneen");
    myservo.write(170);
  }
  else if(uid=="15AE1CC3")
  {
    Serial.print(":Smit");
    lcd.clear();
    lcd.print(" ACCESS GRANTED");
    lcd.setCursor(0,1);
    lcd.print("      Smit");
    myservo.write(10);
  }
  else
  {
    Serial.print("ACCESS DENIED");
    lcd.clear();
    lcd.print("  ACCESS DENIED");
    myservo.write(170);
  }
  delay(5000);
  myservo.write(170);
  lcd.clear();
  lcd.print("    Scan Tag");
  return;
}
