#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Button.h"
#include <vector>
#include <map>
#include <cstdlib>

class Game {
    private:
        int numPlayers; // total number of players in game
        int currPlayer; // current player turn (numbered 0 -> n - 1)
        std::vector<Player> players; // vector of n Player objects
        int finalPosition; // last square number + 1
        std::map<int, int> slides; // maps all slides from curr to next position
        int difficulty; // 0 is easy, 1 is hard

        // int getNumPlayers(Button _b1, Button _b2, Button _b3, Button _b4); // use buttons to get number of players
        std::vector<Player> setPlayers(int num); // set a vector with specified number of players
        int setGameDifficulty(); // use distance sensor to get user input difficult (either easy or hard)
    
    public:
        Game(); // Constructor
        void nextPlayer(); // updates current player to next player
        int getGameDifficulty(); // get game difficulty (0 is easy, 1 is hard);
        bool checkWinner(); // checks if current player has won the game
        int rollDice(); // picks random number from 1-6
        int getCurrPlayerPos(); // get current player position
        void setCurrPlayerPos(int pos); // set current player new position
        int checkSlide(int pos); // check if specified position is a slide/ladder
        int getCurrPlayerNumber(); // get current player number
};

#endif GAME_H


/*
Important code with pointers when making vector of player objects
vector<Player> v;
Player *p = new Player;
v.push_back(*p);
cout << "Player position: " << v[0].getPosition() << endl;
v[0].setPosition(12);
cout << "Player new position: " << v[0].getPosition() << endl;
*/
