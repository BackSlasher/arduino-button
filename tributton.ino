#include <Keyboard.h>

// Config

int GREEN_KEY = KEY_DOWN_ARROW;
int RED_KEY = KEY_UP_ARROW;
int KEYBOARD_DELAY = 100; // How long to wait between keypresses

// Electronic config

int buttonBreakPin = 8;
int buttonGreenPin = 5;
int buttonRedPin = 2;
int ledPin = 2;

// Code

void setup() {
  pinMode(buttonGreenPin, INPUT_PULLUP);
  pinMode(buttonRedPin, INPUT_PULLUP);
  pinMode(buttonBreakPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void setButtons() {
  int buttonGreen = !digitalRead(buttonGreenPin);
  int buttonRed = digitalRead(buttonRedPin);
  int buttonBreak = digitalRead(buttonBreakPin);
  
  if(buttonBreak) {
    return;
  } else if (buttonGreen) {
    Keyboard.write(GREEN_KEY);
  } else if (buttonRed) {
    Keyboard.write(RED_KEY);
  }
}

void loop() {
  setButtons();
  delay(KEYBOARD_DELAY);
}
