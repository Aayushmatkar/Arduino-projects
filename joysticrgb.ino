const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
 int redPin = 9; //red pin of RGB led plugged into digital pin 9
 int greenPin = 10; // green pin plugged into digital pin 10
 int bluePin = 11;//and so on
int YPIN; //declaring YPIN an integer for later
int XPIN;
int SWPIN;
void setup() {
  pinMode(SW_pin, INPUT); // Switch pin is an input
  digitalWrite(SW_pin, HIGH); //set to high
  Serial.begin(9600); //begin serial monitor
  pinMode(redPin, OUTPUT); // declares RGB LED as an output
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}

void setColor(int red, int green, int blue) //sets up format for colors
{
  analogWrite(redPin, red); 
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void loop() {
  int YPIN = analogRead(Y_pin);  //sets the number thats comes out of analogRead(Y_pin); equal to a new variable
  int XPIN = analogRead(X_pin);
  int SWPIN = digitalRead(SW_pin);
  
  Serial.print("Switch:"); //in serial monitor print switch
  Serial.print(digitalRead(SW_pin)); //next to switch print the value of SW_pin
  Serial.print("  ");
  Serial.print("X-axis:");
  Serial.print(analogRead(X_pin));
  Serial.print("  ");
  Serial.print("Y-axis:");
  Serial.println(analogRead(Y_pin));
  if(YPIN == 0) {setColor(100, 80, 0); delay(100);} //if YPIN is equal to 0, set the color
  else {setColor(0, 0, 0);}
  
  if(YPIN == 1023) {setColor(225, 0, 225); delay(100);}
    else {setColor(0, 0, 0);}
    
  if(XPIN == 0) {setColor(0, 0, 225); delay(100);}
    else {setColor(0, 0, 0);}

  if(XPIN == 1023) {setColor(0, 225, 0); delay(100);}
    else {setColor(0, 0, 0);}

   if(SWPIN == LOW) {setColor(80, 20, 0); delay(100);} //if SWPIN is low set color
    else {setColor(0, 0, 0);}

}
