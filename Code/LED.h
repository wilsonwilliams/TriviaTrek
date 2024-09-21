#ifndef LED_H
#define LED_H

#include <Adafruit_NeoPixel.h>

class LED {
    private:
        int pin;
    
    public:
        LED();    // Constructor
        void off();     // Turn all LEDs off
        void allGreen();    // Turn all LEDs green
        void allRed();      // Turn all LEDs red
};

#endif LED_H
