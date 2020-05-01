#include "UsbKeyboard.h"
#include <util/delay.h>
#define BUTTON_PIN 10

void setup() {
 pinMode(BUTTON_PIN, INPUT);
 TIMSK0 &= !(1<<TOIE0); // disable interrupt so we can use the UsbKeyboard library
}

const char token[] = "INSERT_TOKEN_HERE";

void loop() {
  UsbKeyboard.update();
  if (digitalRead(BUTTON_PIN) == 0) {
    for(int i =0; i < strlen(token); i++ ) {
      UsbKeyboard.sendKeyStroke(token[i]); // send every key
    }
    _delay_ms(1000); // delay a bit so it won't trigger twice 
  }
}
