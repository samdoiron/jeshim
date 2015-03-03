#include "collidable.hh"
#include <stdexcept>

#include <iostream>

namespace jesh {

Collidable::Collidable(Dimensions dim) :
  dimensions(dim),
  position(0, 0) {
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

double Collidable::getTop() {
    return position.getY();
}

double Collidable::getBottom() {
    return position.getY() + dimensions.getHeight();
}

double Collidable::getLeft() {
    return position.getX();
}

double Collidable::getRight() {
    return position.getX() + dimensions.getWidth();
}

double Collidable::getWidth() {
    return dimensions.getWidth();
}

double Collidable::getXMiddle() {
    return position.getX() + dimensions.getWidth() / 2;
}

double Collidable::getYMiddle() {
    return position.getY() + dimensions.getHeight() / 2;
}

double Collidable::getHeight() {
    return dimensions.getHeight();
}

void Collidable::setLeft(double newLeft) {
    position.setX(newLeft);
}

void Collidable::setRight(double newRight) {
    position.setX(position.getX() + (newRight - getRight()));
}

void Collidable::setTop(double newTop) {
    position.setY(newTop);
}

void Collidable::setBottom(double newBottom) {
    position.setY(position.getY() + (newBottom - getBottom()));
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
        getLeft()       <= other.getRight()  &&
        other.getLeft() <= getRight()        &&
        getTop()        <= other.getBottom() &&
        other.getTop()  <= getBottom()
    );
}

Collidable::~Collidable() {
    // This space intentionally left blank.
}

}
