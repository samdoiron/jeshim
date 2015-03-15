#include "slime.hh"

#include "sprite.hh"
#include "singlespriteview.hh"
#include "entity.hh"
#include "tile.hh"
#include "units.hh"

#include <random>
#include <iostream>

namespace jesh {

const double kRunTime = 1.5 SECONDS;
const double kKnockbackTime = 1;

Slime::Slime() :
    Enemy(view, Dimensions(38, 13), 5),
    view(*this, Sprite::get(Sprite::kSlime)),
    moveSpeed(100),
    timeRunning(kRunTime),
    isKnockedBack(false),
    velocity(0, 0) {
}

void Slime::advance(double secondsPassed) {
    timeRunning += secondsPassed;
    if (isKnockedBack) {
        topLeft += velocity * secondsPassed;
        if (timeRunning >= kRunTime) {
            setRandomVelocity();
            timeRunning = 0;
        }
    } else {
        timeSinceKnockback += secondsPassed;
        if (timeSinceKnockback > kKnockbackTime) {
            isKnockedBack = false;
        }
    }
}

void Slime::handleCollision(Slime&) {
}

void Slime::takeDamage(Point theSource, int theDamage) {
    if (isKnockedBack) {
        isKnockedBack = true;
        timeSinceKnockback = 0;
    }
}

void Slime::sendCollision(Collidable &other) {
    other.handleCollision(*this);
    Enemy::sendCollision(other);
}

// --- private

void Slime::setRandomVelocity() {
    velocity = Vector::random(moveSpeed);
}

}

