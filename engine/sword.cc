#include "sword.hh"
#include "swordview.hh"
#include "entity.hh"

namespace jesh {

Sword::Sword() :
    Entity(view, Dimensions(3, 10)),
    view(*this),
    isSwinging(false),
    timeSinceSwing(0),
    timeToSwing(0) {
}

void Sword::swing(double theTimeToSwing) {
    timeToSwing = theTimeToSwing;
    timeSinceSwing = 0;
    isSwinging = true;
}

void Sword::advance(double) {
}

int Sword::getDamage() {
    return 1;
}

void Sword::sendCollision(Collidable &other) {
    other.handleCollision(*this);
}

}

