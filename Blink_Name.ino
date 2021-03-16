//Task 2.1P Particle - First Name Blinky

#define SIZE 26

int led = D7; 

const int TIME_UNIT = 250; //ms
const int DOT = TIME_UNIT;
const int DASH = 3 * TIME_UNIT;
const int SYMBOL_SPACE = TIME_UNIT;
const int LETTER_SPACE = 3 * TIME_UNIT - SYMBOL_SPACE; //500ms
const int WORD_SPACE   = 7 * TIME_UNIT - LETTER_SPACE; //1250ms

const char* name = "SHASHVAT"; //Username

//Array of MorseCode for letters of English Language A to Z
const char* letters[SIZE]={
// uppar and lower case same code
// A to I
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
// J to R 
".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
// S to Z
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." 
};

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  int size = strlen(name);
  
  //loop through the name
  for (int i=0; i<size; i++){`
    const char ch = tolower(name[i]);

    if (isAlpha(ch)){
      int index = (int)ch - 'a';
      const char* morseSymbols = letters[index];
      int count = strlen(morseSymbols);

      for (int i=0; i<count; i++){
        digitalWrite(led, HIGH); // turn the LED on
        int symbolTime;
        char symbol = morseSymbols[i];

        if (symbol == '.')
          symbolTime = DOT;
        else
          symbolTime = DASH; 
        delay(symbolTime);
        digitalWrite(led, LOW); // turn the LED off
        delay(SYMBOL_SPACE);
      }
      delay(LETTER_SPACE);
    }
  }
  delay(WORD_SPACE);
}