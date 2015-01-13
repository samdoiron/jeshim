#include "point.hh"

namespace jesh {

Point::Point(float _x, float _y) {
    this->x = _x;
    this->y = _y;
}

float Point::getX() {
    return x;
}

float Point::getY() {
    return y;
}

void Point::moveRelative(float dx, float dy) {
    x += dx;
    y += dy;
}

}


