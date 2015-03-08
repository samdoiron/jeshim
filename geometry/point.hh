#ifndef JESH_POINT_H_
#define JESH_POINT_H_

#include <SFML/window.hpp>
#include "vector.hh"

namespace jesh {

// Deal with circular dependency of Vector and Point.
class Vector;

class Point {
    public:
        Point(double, double);
        double getX();
        double getY();
        void setX(double);
        void setY(double);
        void moveRelative(double x, double y);
        void moveRelative(Vector);
        double distanceTo(Point);
        Vector operator-(Point);
        Point operator+(Vector);
        Point operator+=(Vector);
        sf::Vector2f asSFMLVector();
    private:
        double x, y;
};

}

#endif // JESH_POINT_H_

