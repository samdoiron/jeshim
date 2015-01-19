#include "point.hh"
#include <SFML/graphics.hpp>

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

sf::Vector2f Point::asSFMLVector() {
    return sf::Vector2f(x, y);
}

}


