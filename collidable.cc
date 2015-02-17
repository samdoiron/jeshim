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
  // Basic rectangle collisions
    return (
        // My top left before of their top right
        topLeft().getX() < other.topRight().getX()   &&

        // My top right after of their top left
        topRight().getX() > other.topLeft().getX()   &&

        // My top left above their bottom left
        topLeft().getY() > other.bottomLeft().getY() &&

        // My bottom left below their top left
        bottomLeft().getY() < other.topLeft().getY()
    );
}
Point Collidable::topLeft() {
    return position;
}

Point Collidable::topRight() {
    return position + Vector(dimensions.getWidth(), 0);
}

Point Collidable::bottomLeft() {
    return position + Vector(0, dimensions.getHeight());
}

Point Collidable::bottomRight() {
    return position + Vector(dimensions.getWidth(), dimensions.getHeight());
}

Collidable::~Collidable() {
    // This space intentionally left blank.
}

}
