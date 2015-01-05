#include "player.hh"

#include "dimensions.hh"
#include "point.hh"

#include <iostream>

#define PLAYER_HEIGHT 64
#define PLAYER_WIDTH 32

namespace jesh {

Player::Player(Point start) :
    Entity(Dimensions(PLAYER_WIDTH, PLAYER_HEIGHT), start) {
}

void Player::advance(float) {
    // std::cout << "I am advanced" << std::endl;
}

}
