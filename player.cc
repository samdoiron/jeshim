#include "player.hh"

#include "dimensions.hh"
#include "event.hh"
#include "eventemitter.hh"
#include "point.hh"
#include "keycode.hh"

#include <iostream>
#include <typeinfo>
#include <tgmath.h>
#include <stdexcept>
#include <cmath>

#define PLAYER_HEIGHT 64
#define PLAYER_WIDTH 32

namespace jesh {

const KeyCode kMoveUp    = kUp;
const KeyCode kMoveDown  = kDown;
const KeyCode kMoveLeft  = kLeft;
const KeyCode kMoveRight = kRight;

const double kRunSpeed = 2000; // Pixels per second

Player::Player(EventEmitter &_emitter, Point start) :
    Entity(Dimensions(PLAYER_WIDTH, PLAYER_HEIGHT), start),
    emitter(_emitter),
    isRunningX(false),
    isRunningY(false) {
    this->emitter.addListener(kKeyPress, *this);
    this->emitter.addListener(kKeyRelease, *this);
}

void Player::advance(double secondsPassed) {
    if (secondsPassed > 0.001) {
        position.moveRelative(velocity * secondsPassed);
    }
}

// Event handling

void Player::handleEvent(KeyPressEvent &event) {
    KeyCode key = event.getKeyCode();

    // XXX temporary
    if (key == kMoveUp) {
        velocity.setY(-kRunSpeed);
    } else if (key == kMoveDown) {
        velocity.setY(kRunSpeed);
    } else if (key == kMoveLeft) {
        velocity.setX(-kRunSpeed);
    } else if (key == kMoveRight) {
        velocity.setX(kRunSpeed);
    }
}

void Player::handleEvent(KeyReleaseEvent &event) {
    KeyCode key = event.getKeyCode();
    if (key == kMoveUp || key == kMoveDown) {
        velocity.setY(0);
    } else if (key == kMoveLeft || key == kMoveRight) {
        velocity.setX(0);
    }
}

void Player::handleEvent(Event&) {
    throw std::runtime_error("Player cannot handle event!");
}

}
