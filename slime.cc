#include "slime.hh"

#include "singlespriteview.hh"
#include "entity.hh"
#include "tile.hh"
#include "debugutils.hh"

#include <random>
#include <iostream>

namespace jesh {

const double kMaxRunTime = 1.5;

Slime::Slime() :
    Enemy(view, Dimensions(64, 25)),
    view(*this, "img/slime.png"),
    moveSpeed(100),
    timeRunning(1),
    timeToRun(0),
    velocity(0, 0) {
}

void Slime::advance(double secondsPassed) {
    timeRunning += secondsPassed;
    if (timeRunning >= timeToRun) {
        setRandomVelocity();
        timeRunning = 0;
        timeToRun = ((double)rand() / RAND_MAX) * kMaxRunTime;
    }
    topLeft += velocity * secondsPassed;
    Debug::getInstance().drawVector(getMiddle(), velocity);
}

void Slime::handleCollision(Slime&) {
}

void Slime::sendCollision(Collidable &other) {
    other.handleCollision(*this);
    Enemy::sendCollision(other);
}

// private

void Slime::setRandomVelocity() {
    velocity = Vector::random(moveSpeed);
}

}



