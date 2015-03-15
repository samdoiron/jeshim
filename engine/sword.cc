#include "sword.hh"
#include "swordview.hh"
#include "entity.hh"
#include "geometry/direction.hh"
#include "units.hh"
#include "enemy.hh"
#include "util/exceptions.hh"

#include <iostream>

namespace jesh {

const double kSwordSwingDistance = 32 PIXELS;
const double kSwordWidth = 3;
const double kSwordLength = 32;

Sword::Sword() :
    Entity(view, Dimensions(3 PIXELS, 10 PIXELS)),
    view(*this),
    facing(kUp),
    origin(0, 0),
    isSwinging(false),
    timeSinceSwing(0),
    timeToSwing(0) {
}

void Sword::swing(Direction theDirection, double theTimeToSwing IN SECONDS) {
    if (isSwinging) {
        return;
    }

    isSwinging = true;
    timeToSwing = theTimeToSwing;
    timeSinceSwing = 0;
}

void Sword::advance(double theSecondsPassed) {
    if (isSwinging) {
        timeSinceSwing += theSecondsPassed;
        updatePosition();
        if (timeSinceSwing > timeToSwing) {
            isSwinging = false;
            velocity = Vector(0, 0);
        }
    } else {
        setPosition(origin);
    }
}

int Sword::getDamage() const {
    return 1;
}

void Sword::setOrigin(Point theOrigin) {
    // Position is based on top-left, but we are given the position
    // of the "handle" of the sword, so we have to convert.
    switch (facing) {
        case kUp:
            origin = theOrigin + Vector(0, -kSwordLength);
            break;
        case kDown:
            origin = theOrigin;
            break;
        case kLeft:
            origin = theOrigin + Vector(0, -kSwordWidth);
            break;
        case kRight:
            origin = theOrigin;
            break;
        default:
            break;
    }
}

void Sword::setDirection(Direction theDirection) {
    double magnitude = kSwordSwingDistance / timeToSwing;
    facing = theDirection;
    switch (theDirection) {
        case kUp:
            velocity = Vector(magnitude, 0);
            break;
        case kDown:
            velocity = Vector(-magnitude, 0);
            break;
        case kLeft:
            velocity = Vector(0, -magnitude);
            break;
        case kRight:
            velocity = Vector(0, magnitude);
            break;
        default:
            throw_error("Invalid direction");
    }
    updateDimensions();
}

// --- Collisions

void Sword::sendCollision(Collidable &theOther) {
    theOther.handleCollision(*this);
}

void Sword::handleCollision(Collidable&) {
}

void Sword::handleCollision(Enemy& enemy) {
    if (isSwinging) {
        enemy.takeDamage(getMiddle(), getDamage());
    }
}

// --- private

void Sword::updateDimensions() {
    switch (facing) {
        case kUp:
            setDimensions(Dimensions(kSwordWidth, kSwordLength));
            break;
        case kDown:
            setDimensions(Dimensions(kSwordWidth, kSwordLength));
            break;
        case kLeft:
            setDimensions(Dimensions(-kSwordLength, kSwordWidth));
            break;
        case kRight:
            setDimensions(Dimensions(kSwordLength, kSwordWidth));
            break;
        default:
            break;
    }
}

void Sword::updatePosition() {
    setPosition(origin + (velocity * timeSinceSwing));
}

}

