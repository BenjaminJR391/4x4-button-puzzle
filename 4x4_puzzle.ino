#include <ESP8266WiFi.h>
#include <Keypad.h>

const char* ssid = JTSH;
const char* password = Garden321;
const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
{'A', 'B', 'C', 'D'},
{'E', 'F', 'G', 'H'},
{'I', 'J', 'K', 'L'},
{'M', 'N', 'O', 'P'}

};

void setup() {
WiFi.hostname("JTSH");
WiFi.begin(ssid, password);

}

void loop() {

char Keypad::getKey() {
static char prevKey = 0;
char key = scan();
for (int i = 0; i < ROWS; i++) {
  
    }
  }
}
