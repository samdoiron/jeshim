#include "point.hh"

namespace jesh {

Point::Point(float _x, float _y) {
    this->x = _x;
    this->y = _y;
}

float Point::getX() {
    return this->x;
}

float Point::getY() {
    return this->y;
}

}


