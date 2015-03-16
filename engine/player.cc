#include "player.hh"

#include "enemy.hh"
#include "slime.hh"
#include "units.hh"

#include "geometry/dimensions.hh"
#include "geometry/point.hh"
#include "geometry/direction.hh"

#include "util/exceptions.hh"

#include <iostream>
#include <typeinfo>
#include <tgmath.h>
#include <cmath>

#define PLAYER_HEIGHT 40
#define PLAYER_WIDTH 33

namespace jesh {

const double kRunSpeed          = 250 PIXELS PER SECOND;
const double kKnockbackTime     = 1 SECOND;
const double kKnockbackDistance = 1000 PIXELS;
const double kSwordSwingTime    = 0.25 SECONDS;
const double kKnockbackDecay    = 0.8;

const int kStartingHealth = 6;

const sf::Keyboard::Key kMoveLeft   = sf::Keyboard::Left;
const sf::Keyboard::Key kMoveUp     = sf::Keyboard::Up;
const sf::Keyboard::Key kMoveRight  = sf::Keyboard::Right;
const sf::Keyboard::Key kMoveDown   = sf::Keyboard::Down;
const sf::Keyboard::Key kSwingSword = sf::Keyboard::Z;

Player::Player() :
    Entity(view, Dimensions(PLAYER_WIDTH, PLAYER_HEIGHT)),
    health(kStartingHealth),
    velocity(0, 0),
    facing(kDown),
    view(*this),
    knockbackTimer(kKnockbackTime),
    swungLastFrame(false) {

    setPosition(Point(500, 500));

    knockbackTimer.onDone([&] {
        currentKnockback = Vector(0, 0);
        isKnockedBack = false;
    });
}

void Player::advance(double theSecondsPassed) {
    readKeyboard();
    move(theSecondsPassed);
    knockbackTimer.advance(theSecondsPassed);
    applyKnockback(theSecondsPassed);
    updateFacing();
    updateSword(theSecondsPassed);
}

Sword &Player::getSword() {
    return sword;
}

// --- Collisions

void Player::sendCollision(Collidable &theCollidable) {
    theCollidable.handleCollision(*this);
}

void Player::handleCollision(Enemy &enemy) {
    if (!isKnockedBack) {
        knockbackFrom(enemy);
        health -= 1;
        checkPulse();
    }
}

// --- private

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
    if (sf::Keyboard::isKeyPressed(kSwingSword)) {
        if (!swungLastFrame) {
            swingSword();
            swungLastFrame = true;
        }
    } else {
        swungLastFrame = false;
    }
}

void Player::move(double theSecondsPassed) {
    moveRelative(velocity * theSecondsPassed);
}

void Player::applyKnockback(double theSecondsPassed) {
    if (isKnockedBack) {
        moveRelative(currentKnockback * theSecondsPassed);
        currentKnockback *= kKnockbackDecay;
    }
}

void Player::updateSword(double theSecondsPassed) {
    sword.setDirection(facing);
    switch (facing) {
        case kUp:
            sword.setOrigin(getTopLeft());
            break;
        case kDown:
            sword.setOrigin(getBottomRight());
            break;
        case kLeft:
            sword.setOrigin(getBottomLeft());
            break;
        case kRight:
            sword.setOrigin(getTopRight());
            break;
        default:
            throw_error("Invalid direction");
    }
    sword.advance(theSecondsPassed);
}

void Player::swingSword() {
    // Swing left-to-right, from PoV of player. This means rotation position by 1.
    Direction toSwing;
    switch (facing) {
        case kUp:
            toSwing = kRight;
            break;
        case kDown:
            toSwing = kLeft;
            break;
        case kLeft:
            toSwing = kUp;
            break;
        case kRight:
            toSwing = kDown;
            break;
        default:
            throw_error("Invalid direction");
    }
    sword.swing(toSwing, kSwordSwingTime);
}

void Player::knockbackFrom(Collidable &theOther) {
    currentKnockback = (getMiddle() - theOther.getMiddle())
        .withMagnitude(kKnockbackDistance);
    isKnockedBack = true;
    knockbackTimer.start();
}

void Player::checkPulse() {
    if (health <= 0) {
        // std::exit(0);
    }
}

void Player::updateFacing() {
    if (velocity.getY() > 0) {
        facing = kDown;
    } else if (velocity.getY() < 0) {
        facing = kUp;
    } else if (velocity.getX() > 0) {
        facing = kRight;
    } else if (velocity.getX() < 0) {
        facing = kLeft;
    } else {
        // Standing still (velocity = 0, 0) so maintain previous facing.
    }
}

Player::~Player() {
}

}
