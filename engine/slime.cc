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
}

// Make a BIGGER slime?
void Slime::handleCollision(Slime&) {
}

void Slime::takeDamage(Point theSource, int theDamage) {
    health -= 1;
    isKnockedBack = true;
    timeSinceKnockback = 0;
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

