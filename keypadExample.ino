
#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  };
char num1 = '4';
char num2 = 'A';
//char num3;
//char num4;

byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char customKey = customKeypad.getKey();

  if(customKey){
    Serial.print(customKey);
  }
  if(customKey == num1){
    char keyPressed = customKeypad.waitForKey();
    Serial.print("here");
    if (keyPressed == num2){
      Serial.print("\nYou cracked the code!\n");
    }
  }
}
