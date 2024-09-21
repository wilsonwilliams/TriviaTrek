#include "Display.h"

// Constructor
Display::Display() {
  csPin = 16;     // chip select pin (change depending on GPIO pin #)
  pinMode(csPin, OUTPUT);
  // digitalWrite(csPin, HIGH);

  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV128);
}

// Clear the screen
void Display::clearScreen() {
  digitalWrite(csPin, LOW); // select LCD
  SPI.transfer('|'); // put LCD into setting mode
  SPI.transfer('-'); // send clear screen command
  digitalWrite(csPin, HIGH); // de-select LCD
}

// Send data to LCD screen
void Display::spiSendString(char* data) {
  digitalWrite(csPin, LOW); //Drive the CS pin low to select OpenLCD
  for(byte x = 0 ; data[x] != '\0' ; x++) //Send chars until we hit the end of the string
    SPI.transfer(data[x]);
  digitalWrite(csPin, HIGH); //Release the CS pin to de-select OpenLCD
}

// Welcome screen
void Display::displayStart() {
  clearScreen();
  char data[32];
  sprintf(data, "Welcome to      Trivia Trek!");
  spiSendString(data);
  delay(2000);
  clearScreen();
  sprintf(data, "Select Number   of Players");
  spiSendString(data);
}

// Display current player turn
void Display::displayCurrPlayer(int n) {
  clearScreen();
  char data[32];
  sprintf(data, "Player %d\'s Turn Push Blue Button", n);
  spiSendString(data);
}

// Display "Picking a question..."
void Display::displayGettingQ() {
  clearScreen();
  delay(1000);
  char data[32];
  sprintf(data, "Picking a       question...");
  spiSendString(data);
  delay(2000);
}

// TODO: Implement
// Displays full question on LCD
// Used before showing answer choices
void Display::displayFullQuestion(std::string s) {
  // int length = s.size();
  // int i = 0;
  // char data[32];
  // while (i < length) {
  //   int subLength;
  //   if (length - i < 32) {
  //     subLength = length - i;
  //   } else {
  //     subLength = 32;
  //   }

  //   sprintf(data, s.substr(i, subLength));
  //   spiSendString(data);
  //   delay(3000);
  //   i += 32;
  // }
}


/*

#include <SPI.h>

const int csPin = 16;
int cycles = 0;

void setup() {
  pinMode(csPin, OUTPUT);
  digitalWrite(csPin, HIGH);

  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV128);
}

void loop(){
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);

  cycles++; //Counting cycles! Yay!

  //Send the clear display command to the display - this forces the cursor to return to the beginning of the display
  digitalWrite(csPin, LOW); //Drive the CS pin low to select OpenLCD
  SPI.transfer('|'); //Put LCD into setting mode
  SPI.transfer('-'); //Send clear display command
  digitalWrite(csPin, HIGH); //Release the CS pin to de-select OpenLCD

  char tempString[50]; //Needs to be large enough to hold the entire string with up to 5 digits
  sprintf(tempString, "Cycles: %d", cycles);
  spiSendString(tempString);

  //25ms works well
  //15ms slight flickering
  //5ms causes flickering
  delay(250);
}

//Sends a string over SPI
void spiSendString(char* data)
{
  digitalWrite(csPin, LOW); //Drive the CS pin low to select OpenLCD
  for(byte x = 0 ; data[x] != '\0' ; x++) //Send chars until we hit the end of the string
    SPI.transfer(data[x]);
  digitalWrite(csPin, HIGH); //Release the CS pin to de-select OpenLCD
}


*/
