#include "player.hh"

#include "enemy.hh"
#include "slime.hh"

#include "geometry/dimensions.hh"
#include "geometry/point.hh"

#include "util/exceptions.hh"

#include <iostream>
#include <typeinfo>
#include <tgmath.h>
#include <cmath>

#define PLAYER_HEIGHT 56
#define PLAYER_WIDTH 33

namespace jesh {

const double kRunSpeed  = 300; // Pixels per second
const double kKnockbackTime = 0.5;
const double kKnockbackDistance = 1000;

const int kStartingHealth = 6;

const sf::Keyboard::Key kMoveLeft  = sf::Keyboard::Left;
const sf::Keyboard::Key kMoveUp    = sf::Keyboard::Up;
const sf::Keyboard::Key kMoveRight = sf::Keyboard::Right;
const sf::Keyboard::Key kMoveDown  = sf::Keyboard::Down;

Player::Player() :
  Entity(view, Dimensions(PLAYER_WIDTH, PLAYER_HEIGHT)),
    health(kStartingHealth),
  velocity(0, 0),
  view(*this) {
    setPosition(Point(500, 500));
}

void Player::advance(double secondsPassed) {
    readKeyboard();
    moveRelative(velocity * secondsPassed);
    if (timeSinceKnockback >= kKnockbackTime) {
        currentKnockback = Vector(0, 0);
        isKnockedBack = false;
    }
    if (isKnockedBack) {
        timeSinceKnockback += secondsPassed;
        moveRelative(currentKnockback * secondsPassed);
        currentKnockback *= 0.8;
    }
}

// Event handling

void Player::readKeyboard() {
    velocity = Vector(0, 0);
    if (sf::Keyboard::isKeyPressed(kMoveUp)) {
        velocity.setY(-kRunSpeed);
    } else if (sf::Keyboard::isKeyPressed(kMoveDown)) {
        velocity.setY(kRunSpeed);
    }
    if (sf::Keyboard::isKeyPressed(kMoveLeft)) {
        velocity.setX(-kRunSpeed);
    } else if (sf::Keyboard::isKeyPressed(kMoveRight)) {
        velocity.setX(kRunSpeed);
    }
}

// --- Collisions

void Player::handleCollision(Enemy &enemy) {
    if (!isKnockedBack) {
        knockbackFrom(enemy);
        health -= 1;
        checkPulse();
    }
}

void Player::sendCollision(Collidable &other) {
  other.handleCollision(*this);
}

// private

void Player::knockbackFrom(Collidable &theOther) {
    Vector newKnockback = getMiddle() - theOther.getMiddle();
    newKnockback.setMagnitude(kKnockbackDistance);
    currentKnockback = newKnockback;
    timeSinceKnockback = 0;
    isKnockedBack = true;
}

void Player::checkPulse() {
    if (health <= 0) {
        std::exit(0);
    }
}

Player::~Player() {
}

}
