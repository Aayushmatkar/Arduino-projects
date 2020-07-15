void setup() {
  pinMode(12,INPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);
int x;
int y;
}

void loop() {
  int x;
int y;
  x=digitalRead(12);
  y=analogRead(A1);
  Serial.print("Analog=");
  Serial.print(y);
  delay(1000);

  Serial.print("\t digital=");
  Serial.println(x);
  delay(1000);

}
