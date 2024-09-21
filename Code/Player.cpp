#include "Player.h"

// Constructor
Player::Player() {
    position = 1;
}

int Player::getPosition() {
    return position;
}

void Player::setPosition(int newPosition) {
    position = newPosition;
}
