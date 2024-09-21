#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        int position; // player's square number on the map
    
    public:
        Player(); // Constructor
        int getPosition(); // get player position
        void setPosition(int newPosition); // set player new position
};

#endif PLAYER_H
