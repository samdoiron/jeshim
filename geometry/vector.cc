#include "vector.hh"
#include "point.hh"

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

double Vector::getX() {
    return deltaX;
}

double Vector::getY() {
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

double Vector::getMagnitude() {
    return std::sqrt((deltaX * deltaX) + (deltaY * deltaY));
}

Vector Vector::operator*(double multiplier) {
    return Vector(deltaX * multiplier, deltaY * multiplier);
}

Vector Vector::operator*=(double multiplier) {
    deltaX *= multiplier;
    deltaY *= multiplier;
    return *this;
}

Vector Vector::operator-(double subtraction) {
    return Vector(deltaX - subtraction, deltaY - subtraction);
}

Vector Vector::operator-=(double subtraction) {
    deltaX -= subtraction;
    deltaY -= subtraction;
    return *this;
}

Vector Vector::operator+(Vector theOther) {
    return Vector(deltaX + theOther.getX(), deltaY + theOther.getY());
}

Vector Vector::operator+=(Vector theOther) {
    deltaX += theOther.getX();
    deltaY += theOther.getY();
    return *this;
}

}


