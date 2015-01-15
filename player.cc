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

#define GAME_WIDTH 800
#define GAME_HEIGHT 600

namespace jesh {

const KeyCode kMoveUp    = kUp;
const KeyCode kMoveDown  = kDown;
const KeyCode kMoveLeft  = kLeft;
const KeyCode kMoveRight = kRight;
const KeyCode kRun       = kZ;

const double kRunSpeed  = 500; // Pixels per second

Player::Player(EventEmitter &_emitter, Point start) :
    Entity(Dimensions(PLAYER_WIDTH, PLAYER_HEIGHT), start),
    emitter(_emitter),
    velocity(kRunSpeed, kRunSpeed),
    isRunning(false) {
    emitter.addListener(kKeyPress, *this);
    emitter.addListener(kKeyRelease, *this);
}

void Player::advance(double secondsPassed) {
    Point newPosition = position;
    newPosition.moveRelative(velocity * secondsPassed);

    if (newPosition.getX() < 0 || GAME_WIDTH < newPosition.getX() + PLAYER_WIDTH) {
        velocity.setX(-velocity.getX());
    }
    if (newPosition.getY() < 0 || GAME_HEIGHT < newPosition.getY() + PLAYER_HEIGHT) {
        velocity.setY(-velocity.getY());
    }
    position.moveRelative(velocity * secondsPassed);
}

// Event handling

void Player::handleEvent(KeyPressEvent &event) {
    KeyCode key = event.getKeyCode();

    // XXX temporary
    /* if (key == kMoveUp) { */
    /*     velocity.setY(-kRunSpeed); */
    /* } else if (key == kMoveDown) { */
    /*     velocity.setY(kRunSpeed); */
    /* } else if (key == kMoveLeft) { */
    /*     velocity.setX(-kRunSpeed); */
    /* } else if (key == kMoveRight) { */
    /*     velocity.setX(kRunSpeed); */
    /* } */
}

void Player::handleEvent(KeyReleaseEvent &event) {
    KeyCode releasedKey = event.getKeyCode();
    bool movingLeft  = velocity.getX() < 0;
    bool movingRight = velocity.getX() > 0;
    bool movingUp    = velocity.getY() < 0;
    bool movingDown  = velocity.getY() > 0;

    /* if (releasedKey == kMoveUp && movingUp) { */
    /*     velocity.setY(0); */
    /* } else if (releasedKey == kMoveDown && movingDown) { */
    /*     velocity.setY(0); */
    /* } else if (releasedKey == kMoveLeft && movingLeft) { */
    /*     velocity.setX(0); */
    /* } else if (releasedKey == kMoveRight && movingRight) { */
    /*     velocity.setX(0); */
    /* } */
}

void Player::handleEvent(Event&) {
    throw std::runtime_error("Player cannot handle event!");
}

}
