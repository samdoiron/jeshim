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

const double kRunTime = 1.5 SECONDS;   // Time between random direction switches.
const double kHurtTime = 0.5 SECONDS;  // Time to be "frozen" when hurt.
const double kKnockbackAmount = 400 PIXELS PER SECOND;
const double kKnockbackDecay = 0.9;

Slime::Slime(Level &theLevel) :
    Enemy(view, Dimensions(38, 13), 5),
    hurtTimer(kHurtTime),
    runTimer(kRunTime),
    level(theLevel),
    view(*this, Sprite::get(Sprite::kSlime)),
    moveSpeed(100),
    isHurt(false),
    velocity(0, 0) {

    hurtTimer.onDone([&] {
        isHurt = false;
        currentKnockback = Vector(0, 0);
    });

    runTimer.onDone([&] {
        setRandomVelocity();
        runTimer.start();
    });
    runTimer.start();
    setRandomVelocity();
}

void Slime::advance(double theSecondsPassed) {
    hurtTimer.advance(theSecondsPassed);
    runTimer.advance(theSecondsPassed);
    if (isHurt) {
        moveRelative(currentKnockback * theSecondsPassed);
    } else {
        moveRelative(velocity * theSecondsPassed);
    }
}

// Make a BIGGER slime?
void Slime::handleCollision(Slime&) {
}

void Slime::takeDamage(Point theSource, int theDamage) {
    decreaseHealth(1);
}

void Slime::sendCollision(Collidable &other) {
    other.handleCollision(*this);
    Enemy::sendCollision(other);
}

// --- private

void Slime::decreaseHealth(int theDecrease) {
    health -= theDecrease;
    if (health <= 0) {
        die();
    }
    hurtTimer.start();
    isHurt = true;
}

void Slime::die() {
    level.removeEntity(this);
}

void Slime::setRandomVelocity() {
    velocity = Vector::random(moveSpeed);
}

}

