
//http://www.arduino.cc/playground/uploads/Code/Keypad.zip
#include <Keypad.h>

Password password = Password( "1234" );

const byte ROWS = 4; // Four rows
const byte COLS = 4; //  columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = c;// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 12, 11, 10, 8 };


// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

#define ledPin 13

void setup(){
  
  digitalWrite(ledPin, HIGH);   // sets the LED on
  Serial.begin(9600);
  keypad.addEventListener(keypadEvent); //add an event listener for this keypad
}
  
void loop(){
  keypad.getKey();
}

//take care of some special events
void keypadEvent(KeypadEvent eKey){
  switch (eKey){
    case '*': guessPassword(); break;
    case '#': password.reset(); break;
     default:
           password.append(eKey);
  }
}

void guessPassword(){
     if (password.evaluate()){
           digitalWrite(ledPin,HIGH);
                Serial.print("bien");
     }else{
           digitalWrite(ledPin,LOW);
     }
}
