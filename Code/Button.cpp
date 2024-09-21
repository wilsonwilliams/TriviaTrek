#include "Button.h"

// Constructor
Button::Button(int _pin) {
    pin = _pin;
    pinMode(pin, INPUT_PULLDOWN);
}

// Checks if button is pushed
// Returns 1 if button pushed, else 0
int Button::readButton() {
    return digitalRead(pin);
}
