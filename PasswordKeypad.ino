/*
||  Simple Password Entry Using Matrix Keypad
||  4/5/2012 Updates Nathan Sobieck: Nathan@Sobisource.com
||
*/


//* is to validate password   
//# is to reset password attempt

/////////////////////////////////////////////////////////////////

#include <Password.h> //http://www.arduino.cc/playground/uploads/Code/Password.zip
#include <Keypad.h> //http://www.arduino.cc/playground/uploads/Code/Keypad.zip

Password password = Password( "4444" );

const byte ROWS = 4; // Four rows
const byte COLS = 4; //  columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] =  { 7, 6, 5, 4 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 12, 11, 10, 8 };// Connect keypad COL0, COL1 and COL2 to these Arduino pins.


// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){

  Serial.begin(9600);
  keypad.addEventListener(keypadEvent); //add an event listener for this keypad
}

void loop(){
  keypad.getKey();
}


void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
    case PRESSED:
	Serial.print("Pressed: ");
	Serial.println("*");
	switch (eKey){
	  case '*': checkPassword(); break;
	  case '#': password.reset(); break;
	  default: password.append(eKey);
     }
  }
}

void checkPassword(){
  if (password.evaluate()){
    Serial.println("ENTERED PIN IS RIGHT");
   
  }else{
    Serial.println("ENTERED PIN IS WRONG");
   

  }}
