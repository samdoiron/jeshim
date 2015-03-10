#include "collidable.hh"

#include "geometry/point.hh"
#include "geometry/rectangle.hh"

#include <stdexcept>
#include <iostream>

namespace jesh {

Collidable::Collidable(Rectangle theBody) :
    Rectangle(theBody),
    fixed(false) {
}

void Collidable::setPosition(Point thePosition) {
    setTopLeft(thePosition);
}

Point Collidable::getPosition() {
    return getTopLeft();
}

bool Collidable::isFixed() {
  return fixed;
}

// private

void Collidable::setFixed() {
  fixed = true;
}

void Collidable::setNotFixed() {
  fixed = false;
}

bool Collidable::isCollidingWith(Collidable &other) {
    return isIntersecting(other);
}

Collidable::~Collidable() {
    // This space intentionally left blank.
}

}
