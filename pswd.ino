#include <SPI.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

const byte rowsCount = 4;
const byte columsCount = 4;
const char pass[] = "56713";
char pass_enter[] = "00000";

char keys[rowsCount][columsCount] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

const byte rowPins[rowsCount] =  { 7, 6, 5, 4 };
const byte columnPins[columsCount] ={ 12, 11, 10, 8 };
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);

LiquidCrystal lcd(10);

void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Teclee password>");
  lcd.setCursor(0, 1);
}

int cont = 0;
int verdad = 0;

char uno, dos, tres, cuatro, cinco;
boolean u = false, d = false, t = false, c = false, ci = false;

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.print(key);
    if (u == false) {
      uno = key;
      u = true;
    } else if (d == false) {
      dos = key;
      d = true;
    } else if (t == false) {
      tres = key;
      t = true;
    } else if (c == false) {
      cuatro = key;
      c = true;
    } else if (ci == false) {
      cinco = key;
      ci = true;
    }

    if (cont == 5) {
      
      pass_enter[0] = uno;
      pass_enter[1] = dos;
      pass_enter[2] = tres;
      pass_enter[3] = cuatro;
      pass_enter[4] = cinco;
      lcd.setCursor(0, 1);
      for (int i = 0; i < 5; i++) {
        if (pass[i] == pass_enter[i]) {
          verdad++;
        }
      }
      cont = 0;
      if (verdad == 5) {
        lcd.print("Clave Correcta!!");
        delay(1000);
        verdad = 0;
        for(int i = 0; i <17;i++){
          lcd.setCursor(i, 1);
          lcd.print("_");
        }
        
      } else {
        verdad = 0;
        lcd.print("Clave incorrecta!!");
        delay(1000);
        for(int i = 0; i <17;i++){
          lcd.setCursor(i, 1);
          lcd.print("_");
        }
        
      }
      u = false;
      d = false;
      t = false;
      c = false;
      ci = false;
      lcd.setCursor(0, 1);
    } else {
      
      
      cont++;
      lcd.print(key);
    }


  }
}
