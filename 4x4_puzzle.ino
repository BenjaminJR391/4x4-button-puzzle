const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'A', 'B', 'C', 'D'},
  {'E', 'F', 'G', 'H'},
  {'I', 'J', 'K', 'L'},
  {'M', 'N', 'O', 'P'}};

byte colPins[COLS] = {D4, D3, D2, D1};
byte rowPins[ROWS] = {D8, D7, D6, D5};

int buttons[4][4] = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
const int answerKeys[4][4] = {{1,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
bool wasCorrect = true;

void setup(){
  Serial.begin(115200);
  for (int x = 0; x < COLS; x++) {
    pinMode(colPins[x], OUTPUT);
    digitalWrite(colPins[x], 1);
    }
  for (int y = 0; y < ROWS; y++) {
    pinMode(rowPins[y], INPUT);
    }
}

void loop(){
  //char keyPressed = myKeypad.getKey();
  bool isCorrect = true;
  for (int x = 0; x < COLS; x++) {
    for (int colIndex = 0; colIndex < COLS; colIndex++) {
      //pinMode(colPins[colIndex], OUTPUT);
      digitalWrite(colPins[colIndex], 0);
      }
      digitalWrite(colPins[x], 1);
      for (int y = 0; y < ROWS; y++) {
        buttons[x][y] = digitalRead(rowPins[y]);
        if (buttons[x][y] != answerKeys[x][y]) {
          isCorrect = false;
        }
        Serial.print(buttons[x][y]);3
        
     }
     Serial.println("");
  }
  Serial.println("");

  Serial.println(isCorrect);
  if ((true == wasCorrect) && (false == isCorrect)) {
    wrongAnswer();
  }
  if ((false == wasCorrect) && (true == isCorrect)) {
    answer();
  }

  wasCorrect = isCorrect;
  delay(500);
}

void answer() {
  //TODO: send right answer
  Serial.println("Answer is right");
}

void wrongAnswer() {
  //TODO: restart with wrong answer
  Serial.println("Answer is wrong");
}
