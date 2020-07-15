//http://www.arduino.cc/playground/uploads/Code/Password.zip
#include <Password.h>
//http://www.arduino.cc/playground/uploads/Code/Keypad.zip
#include <Keypad.h>

Password password = Password( "444" );

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
byte rowPins[ROWS] = { 7, 6, 5, 4 };// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 12, 11, 10, 8 };



Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup(){
 
 
 Serial.begin(9600);
 keypad.addEventListener(keypadEvent);
}
 
void loop(){
 keypad.getKey();
}

//take care of some special events
void keypadEvent(KeypadEvent eKey){
 Serial.print("entered password ");
 Serial.println("*");
}
{
    if (password==444)
    {
          
          Serial.print("passwordright");
    }
    else 
    {
         
          Serial.print("n'passwordwrong");
    }
}
}
