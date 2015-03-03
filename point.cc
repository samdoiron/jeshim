#include "point.hh"
#include "vector.hh"
#include <SFML/graphics.hpp>
#include <cmath>

namespace jesh {

Point::Point(double _x, double _y) :
    x(_x),
    y(_y) {
}

double Point::getX() {
    return x;
}

double Point::getY() {
    return y;
}

void Point::setX(double newX) {
    x = newX;
}

void Point::setY(double newY) {
    y = newY;
}

void Point::moveRelative(double dx, double dy) {
    x += dx;
    y += dy;
}

void Point::moveRelative(Vector delta) {
    x += delta.getX();
    y += delta.getY();
}

double Point::distanceTo(Point other) {
    double otherX = other.getX();
    double otherY = other.getY();
    return sqrt(pow(x - otherX, 2) + pow(y - otherY, 2));
}

Vector Point::operator-(Point other) {
    return Vector(
        x - other.getX(),
        y - other.getY()
    );
}

Point Point::operator+(Vector delta) {
    return Point(
        x + delta.getX(),
        y + delta.getY()
    );
}

Point Point::operator+=(Vector delta) {
    moveRelative(delta);
    return *this;
}

sf::Vector2f Point::asSFMLVector() {
    return sf::Vector2f(x, y);
}

}


