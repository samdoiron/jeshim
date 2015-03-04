#include "collidable.hh"

#include "rectangle.hh"

#include <stdexcept>
#include <iostream>

namespace jesh {

Collidable::Collidable(Rectangle theBody) :
    Rectangle(theBody) {
}

void Collidable::setPosition(Point thePosition) {
    setTopLeft(thePosition);
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
