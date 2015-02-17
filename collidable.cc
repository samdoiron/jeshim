#include "collidable.hh"
#include <stdexcept>

#include <iostream>

namespace jesh {

Collidable::Collidable(Dimensions dim) :
  dimensions(dim),
  position(0, 0) {
}

void Collidable::handleCollision(Collidable&) {
    // Don't do anything. Means the child hasn't overridden the default
    // collision handler (normal).
}

bool Collidable::isFixed() {
  return fixed;
}

Point Collidable::getPosition() {
    return position;
}

Dimensions Collidable::getDimensions() {
    return dimensions;
}

// TODO:CLEAN Both getters and setters, needed for collision resolution
// Is this OK?
void Collidable::setPosition(Point newPosition) {
  position = newPosition;
}

// private

void Collidable::setFixed() {
  fixed = true;
}

void Collidable::setNotFixed() {
  fixed = false;
}

bool Collidable::isCollidingWith(Collidable &other) {
    return (
        left() <= other.right()       &&
        other.left() <= other.right() &&
        top() <= other.bottom()       &&
        other.top() <= top()
    );
}

double Collidable::top() {
    return position.getY();
}

double Collidable::bottom() {
    return position.getY() + dimensions.getHeight();
}

double Collidable::left() {
    return position.getX();
}

double Collidable::right() {
    return position.getX() + dimensions.getWidth();
}

Collidable::~Collidable() {
    // This space intentionally left blank.
}

}
