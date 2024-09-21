#ifndef DISPLAY_H
#define DISPLAY_H

#include <SPI.h>
#include <string>
#include "Arduino.h"

class Display {
    private:
        int csPin;
        void spiSendString(char* data);
        void clearScreen(); // clear the screen
    
    public:
        Display(); // Constructor
        void displayStart(); // welcome screen
        void displayCurrPlayer(int n); // "Player n, your turn"
        void displayGettingQ(); // "Picking a question..."
        void displayFullQuestion(std::string s); // Displays whole question on LCD
};

#endif DISPLAY_H
