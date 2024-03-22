#include <MIDI.h>

const int numFaders = 10;
const int faderPins[numFaders] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9};
const int faderCCs[numFaders] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // MIDI controller numbers for faders
int faderValues[numFaders];

const int numButtons = 24;
const int buttonPins[numButtons] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A10, A11, A12, A13, 14, 15, 16, 17, 18, 19, 20, 21}; // Example button pins
const int buttonCCs[numButtons] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43}; // Example MIDI controller numbers for buttons

bool buttonStates[numButtons] = {false};

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  // Initialize MIDI
  MIDI.begin(MIDI_CHANNEL_OMNI);

  // Initialize buttons
  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void loop() {
  // Read fader positions
  for (int i = 0; i < numFaders; i++) {
    faderValues[i] = analogRead(faderPins[i]) >> 3; // Scale analog input to MIDI range (0-127)
    MIDI.sendControlChange(faderCCs[i], faderValues[i], 1); // Channel 1
  }

  // Read button states
  for (int i = 0; i < numButtons; i++) {
    bool state = digitalRead(buttonPins[i]) == LOW; // Active low
    if (state != buttonStates[i]) {
      buttonStates[i] = state;
      if (state) {
        MIDI.sendControlChange(buttonCCs[i], 127, 1); // Button pressed
      } else {
        MIDI.sendControlChange(buttonCCs[i], 0, 1); // Button released
      }
    }
  }

  // Add a small delay to prevent flooding MIDI
  delay(10);
}



