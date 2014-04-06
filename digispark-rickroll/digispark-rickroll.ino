#include <DigiKeyboard.h>
#define PIN_LED 1
#define INTERVAL_MIN 60*5  // The minimum time between rickrolls, in seconds
#define INTERVAL_MAX 60*7  // The minimum time between rickrolls, in seconds

// key codes from p53 of http://www.usb.org/developers/devclass_docs/Hut1_11.pdf
#define KEY_FWDSLASH 56
#define KEY_VOLUP   128
#define KEY_VOLDN   129

void blink(int times) {
  for (int i=0; i<times; i++) {
    digitalWrite(PIN_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(400);               // wait for a second
    digitalWrite(PIN_LED, LOW);    // turn the LED off by making the voltage LOW
    delay(250);
  }
}

// Perform apple keyboard calibration sequence
void calibrateKeyboard() {
  // signal calibrate start
  blink(1);
  // 5 seconds to press continue button
  DigiKeyboard.delay(5000);
  // signal calibrate progress
  blink(2);
  DigiKeyboard.sendKeyStroke(KEY_Z);
  DigiKeyboard.delay(500);
  // signal calibrate progress
  blink(3);
  DigiKeyboard.sendKeyStroke(KEY_FWDSLASH);
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
  DigiKeyboard.print("http://bit.ly/1fYriw1");
  DigiKeyboard.delay(300); // todo find a way to do this without spotlight
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  for (int i=0; i<10; i++) {
    DigiKeyboard.delay(10);
    DigiKeyboard.sendKeyStroke(KEY_VOLUP);
  }
  //signal rickroll sequence complete
  blink(2);
}

void setup() {
  //setup LED as output
  pinMode(PIN_LED, OUTPUT); //LED on Model B
  //do apple keyboard setup
  calibrateKeyboard();
  //2 seconds to dismiss setup window
  DigiKeyboard.delay(2000);
  //rickroll immediately for testing purposes
  rickroll();
}

void loop() {
  // double sec = INTERVAL_MIN + (rand() % (INTERVAL_MAX - INTERVAL_MIN));
  // DigiKeyboard.delay(sec*1000);
  // rickroll();
}