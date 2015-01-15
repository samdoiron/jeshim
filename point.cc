#include "point.hh"

namespace jesh {

Point::Point(double _x, double _y) {
    this->x = _x;
    this->y = _y;
}

double Point::getX() {
    return x;
}

double Point::getY() {
    return y;
}

void Point::moveRelative(double dx, double dy) {
    x += dx;
    y += dy;
}

void Point::moveRelative(Vector delta) {
    x += delta.getX();
    y += delta.getY();
}

}


