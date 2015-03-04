#include "slime.hh"

#include "singlespriteview.hh"
#include "entity.hh"
#include "tile.hh"

#include <random>
#include <iostream>

namespace jesh {

const double kMaxRunLength = 1;

Slime::Slime() :
    Enemy(view, Dimensions(64, 64)),
    view(*this, "slime.png"),
    moveSpeed(500),
    runLength(0),
    velocity(0, 0) {
}

void Slime::advance(double secondsPassed) {
    runLength += secondsPassed;
    if (runLength >= kMaxRunLength) {
        setRandomVelocity();
        runLength = 0;
    }
    topLeft += velocity * secondsPassed;
}

void Slime::handleCollision(Slime&) {
}

void Slime::sendCollision(Collidable &other) {
    other.handleCollision(*this);
    Enemy::sendCollision(other);
}


// private

void Slime::setRandomVelocity() {
    velocity = Vector(
        moveSpeed * ((rand() % 3) - 1),
        moveSpeed * ((rand() % 3) - 1)
    );
}

}



