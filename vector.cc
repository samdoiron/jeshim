#include "vector.hh"

namespace jesh {

Vector::Vector() :
    deltaX(0),
    deltaY(0) {
}

Vector::Vector(float dx, float dy) :
    deltaX(dx),
    deltaY(dy) {
}

float Vector::getX() {
    return deltaX;
}

float Vector::getY() {
    return deltaY;
}

void Vector::setX(float newX) {
    deltaX = newX;
}

void Vector::setY(float newY) {
    deltaY = newY;
}

Vector Vector::operator*(float multiplier) {
    return Vector(deltaX * multiplier, deltaY * multiplier);
}

Vector Vector::operator*=(float multiplier) {
    deltaX *= multiplier;
    deltaY *= multiplier;
    return *this;
}

Vector Vector::operator-(float subtraction) {
    return Vector(deltaX - subtraction, deltaY - subtraction);
}

Vector Vector::operator-=(float subtraction) {
    deltaX -= subtraction;
    deltaY -= subtraction;
    return *this;
}

}


