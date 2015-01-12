#include "player.hh"

#include "dimensions.hh"
#include "event.hh"
#include "eventemitter.hh"
#include "mousemoveevent.hh"
#include "point.hh"

#include <iostream>
#include <typeinfo>
#include <tgmath.h>

#define PLAYER_HEIGHT 64
#define PLAYER_WIDTH 32

namespace jesh {

Player::Player(EventEmitter &_emitter, Point start) :
    Entity(Dimensions(PLAYER_WIDTH, PLAYER_HEIGHT), start),
    emitter(_emitter),
    timeRunning(0) {
    this->emitter.addListener(kMouseMove, *this);
}

void Player::advance(float secondsPassed) {
}

// Event handling

void Player::handleEvent(MouseMoveEvent& event) {
    position = event.getPosition();
}

void Player::handleEvent(Event& event) {
    std::cout << "Generic handling" << std::endl;
}


}
