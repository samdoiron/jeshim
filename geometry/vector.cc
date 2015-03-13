#include "vector.hh"
#include "point.hh"
#include "util/exceptions.hh"

#include <cmath>

namespace jesh {

Vector::Vector() :
    deltaX(1),
    deltaY(1) {
}

/* static */ Vector Vector::random(double magnitude) {
    double angle = (rand() % 360) * ((2 * M_PI) / 360);
    return Vector(
        std::cos(angle) * magnitude,
        std::sin(angle) * magnitude
    );
}

/* static */ Vector Vector::inDirection(Direction theDirection, double theMagnitude) {
    switch (theDirection) {
        case kUp:
            return Vector(0, -theMagnitude);
        case kDown:
            return Vector(0, theMagnitude);
        case kLeft:
            return Vector(-theMagnitude, 0);
        case kRight:
            return Vector(theMagnitude, 0);
        default:
            throw_error("Invalid direction");
    }
}

Vector::Vector(double dx, double dy) :
    deltaX(dx),
    deltaY(dy) {
}

Vector::Vector(Point start, Point stop) :
    Vector(
        stop.getX() - start.getX(),
        stop.getY() - start.getY()
    )
    {
}

double Vector::getX() const {
    return deltaX;
}

double Vector::getY() const {
    return deltaY;
}

void Vector::setX(double newX) {
    deltaX = newX;
}

void Vector::setY(double newY) {
    deltaY = newY;
}

void Vector::setMagnitude(double theMagnitude) {
    double scale = theMagnitude / getMagnitude();
    *this *= scale;
}

double Vector::getMagnitude() const {
    return std::sqrt((deltaX * deltaX) + (deltaY * deltaY));
}

Vector Vector::operator*(double multiplier) const {
    return Vector(deltaX * multiplier, deltaY * multiplier);
}

Vector Vector::operator*=(double multiplier) {
    deltaX *= multiplier;
    deltaY *= multiplier;
    return *this;
}

Vector Vector::operator-(double subtraction) const {
    return Vector(deltaX - subtraction, deltaY - subtraction);
}

Vector Vector::operator-=(double subtraction) {
    deltaX -= subtraction;
    deltaY -= subtraction;
    return *this;
}

Vector Vector::operator+(Vector theOther) const {
    return Vector(deltaX + theOther.getX(), deltaY + theOther.getY());
}

Vector Vector::operator+=(Vector theOther) {
    deltaX += theOther.getX();
    deltaY += theOther.getY();
    return *this;
}

}


