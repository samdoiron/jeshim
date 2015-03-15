#include "slime.hh"

#include "sprite.hh"
#include "singlespriteview.hh"
#include "entity.hh"
#include "tile.hh"
#include "units.hh"
#include "level.hh"

#include <random>
#include <iostream>

namespace jesh {

const double kRunTime = 1.5 SECONDS;
const double kKnockbackTime = 0.5 SECOND;
const double kKnockbackAmount = 400 PIXELS PER SECOND;
const double kKnockbackDecay = 0.9;

Slime::Slime(Level &theLevel) :
    Enemy(view, Dimensions(38, 13), 5),
    currentLevel(theLevel),
    view(*this, Sprite::get(Sprite::kSlime)),
    moveSpeed(100),
    timeRunning(kRunTime),
    isKnockedBack(false),
    velocity(0, 0) {
}

void Slime::advance(double secondsPassed) {
    if (isKnockedBack) {
        moveRelative(currentKnockback * secondsPassed);
        timeSinceKnockback += secondsPassed;
        currentKnockback *= kKnockbackDecay;
        if (timeSinceKnockback > kKnockbackTime) {
            isKnockedBack = false;
        }
    } else {
        timeRunning += secondsPassed;
        moveRelative(velocity * secondsPassed);
        if (timeRunning >= kRunTime) {
            setRandomVelocity();
            timeRunning = 0;
        }
    }
}

void Slime::handleCollision(Slime&) {
}

void Slime::takeDamage(Point theSource, int theDamage) {
    if (!isKnockedBack) {
        currentKnockback = (getMiddle() - theSource)
            .withMagnitude(kKnockbackAmount);
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

