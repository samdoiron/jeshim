#include "player.hh"

#include "dimensions.hh"
#include "event.hh"
#include "exceptions.hh"
#include "eventemitter.hh"
#include "point.hh"
#include "keycode.hh"
#include "enemy.hh"
#include "slime.hh"

#include <iostream>
#include <typeinfo>
#include <tgmath.h>
#include <cmath>

#define PLAYER_HEIGHT 64
#define PLAYER_WIDTH 32

namespace jesh {

const double kRunSpeed  = 400; // Pixels per second

const KeyCode kMoveLeft  = kLeft;
const KeyCode kMoveUp    = kUp;
const KeyCode kMoveRight = kRight;
const KeyCode kMoveDown  = kDown;

Player::Player(EventEmitter &_emitter) :
  Entity(view, Dimensions(PLAYER_WIDTH, PLAYER_HEIGHT)),
  view(*this),
  emitter(_emitter),
  velocity(0, 0) {
    emitter.addListener(kKeyPress, *this);
    emitter.addListener(kKeyRelease, *this);
    setPosition(Point(500, 500));
}

void Player::advance(double secondsPassed) {
    topLeft += (velocity * secondsPassed);
}

// Event handling

void Player::handleEvent(KeyPressEvent &event) {
    KeyCode key = event.getKeyCode();

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
    KeyCode releasedKey = event.getKeyCode();
    bool movingLeft  = velocity.getX() < 0;
    bool movingRight = velocity.getX() > 0;
    bool movingUp    = velocity.getY() < 0;
    bool movingDown  = velocity.getY() > 0;

    // Problem here, where keyUp will halt any velocity, regardless if you're
    // running or not.
    if (releasedKey == kMoveUp && movingUp) {
        velocity.setY(0);
    } else if (releasedKey == kMoveDown && movingDown) {
        velocity.setY(0);
    } else if (releasedKey == kMoveLeft && movingLeft) {
        velocity.setX(0);
    } else if (releasedKey == kMoveRight && movingRight) {
        velocity.setX(0);
    }
}

// --- Collisions

void Player::handleCollision(Enemy &enemy) {
}

void Player::handleEvent(Event&) {
    throw_error("Player cannot handle event!");
}

void Player::sendCollision(Collidable &other) {
  other.handleCollision(*this);
}

Player::~Player() {
}

}
