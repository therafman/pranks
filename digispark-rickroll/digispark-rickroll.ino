#include <DigiKeyboard.h>
#define PIN_LED 1

void blink(int times) {
  for (int i=0; i<times; i++) {
    digitalWrite(PIN_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(400);               // wait for a second
    digitalWrite(PIN_LED, LOW);    // turn the LED off by making the voltage LOW
    delay(250);
  }
}

// Send the key sequence to open a rickroll
void rickroll() {
  //signal rickroll sequence start
  blink(1);
  DigiKeyboard.sendKeyStroke(0); 
  // Open Safari via Spotlight
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  DigiKeyboard.print("Safari");
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1500);
  // Open a rickroll
  DigiKeyboard.sendKeyStroke(KEY_T, MOD_GUI_LEFT);
  DigiKeyboard.delay(300);
  DigiKeyboard.print("http://bit.ly/1e35aW9");
  DigiKeyboard.delay(300); // todo find a way to do this without spotlight
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("f");
  //signal rickroll sequence complete
  blink(3);
}

void setup() {
  //setup LED as output
  pinMode(PIN_LED, OUTPUT); //LED on Model B
  rickroll();
}

void loop() {
  //nada for now
}