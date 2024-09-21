#ifndef BUTTON_H
#define BUTTON_H

#include "Arduino.h"

class Button {
    private:
        int pin; // pin on MicroBit
    
    public:
        Button(int _pin); // constructor
        int readButton(); // checks if button pushed - returns 1 if pushed, else 0
};

#endif BUTTON_H
