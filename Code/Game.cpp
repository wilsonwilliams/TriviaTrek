#include "Game.h"

// Constructor
Game::Game() {
    // Game board info
    finalPosition = 33; // must reach this number to win the game
    slides[2] = 8; // ladder
    slides[7] = 15; // ladder
    slides[10] = 4; // slide
    slides[13] = 24; // ladder
    slides[19] = 14; // slide
    slides[27] = 24; // slide
    slides[32] = 11; // slide
    
    // Game status info
    difficulty = Game::setGameDifficulty(); // set game difficulty
    numPlayers = 3; // TODO: set number of players
    currPlayer = 0; // set Player 1 as currPlayer
    Game::setPlayers(numPlayers); // set Player vector
}

// TODO: Implement
// Get number of players by prompting on LCD and taking button input
// int Game::getNumPlayers(Button _b1, Button _b2, Button _b3, Button _b4) {
//     while(1) {
//         if (_b1.readButton()) {
//             return 1;
//         } else if (_b2.readButton()) {
//             return 2;
//         } else if (_b3.readButton()) {
//             return 3;
//         } else if (_b4.readButton()) {
//             return 4;
//         }
//     }
// }

// Set a vector of Player for number of players
std::vector<Player> Game::setPlayers(int num) {
    for (int i = 0; i < num; ++i) {
        Player *p = new Player;
        players.push_back(*p);
    }
}

// TODO: Implement
// Get the difficulty of the game from distance sensor
int Game::setGameDifficulty() {
    return 0;
}

// Update currPlayer to the next player
void Game::nextPlayer() {
    currPlayer = (currPlayer + 1) % numPlayers;
}

// Get game difficulty
// 0 is easy, 1 is hard
int Game::getGameDifficulty() {
    return difficulty;
}

// Checks if current player has won the game
bool Game::checkWinner() {
    return players[currPlayer].getPosition() >= finalPosition;
}

// Picks a random number from 1-6
int Game::rollDice() {
    int diceRoll = rand() % 6 + 1;
    return diceRoll;
}

// Get current player
int Game::getCurrPlayerPos() {
    return players[currPlayer].getPosition();
}

// Set current player position
void Game::setCurrPlayerPos(int pos) {
    players[currPlayer].setPosition(pos);
}

// Check if specified position is a slide or ladder
int Game::checkSlide(int pos) {
    if (slides.find(pos) == slides.end()) {
        // not a slide or ladder
        return pos;
    }

    // is a slide or ladder
    return slides[pos];
}

// Get current player number
int Game::getCurrPlayerNumber() {
    return currPlayer + 1;
}
