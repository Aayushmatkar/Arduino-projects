String acceptedpassword;
String password="ABCD";


void setup() {
Serial.begin(9600); 
Serial.println("Enter a key");
}

void loop() {
if(Serial.available()>0)
{  acceptedpassword = Serial.readString();

  if(acceptedpassword=="zzz"){
  Serial.println("access granted");
  }
  else{
  (Serial.println("access denied"));
  }
}
}
