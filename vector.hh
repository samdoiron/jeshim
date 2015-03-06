#ifndef JESH_VECTOR_H_
#define JESH_VECTOR_H_

#include "point.hh"

namespace jesh {

class Point;

class Vector {
    public:
        Vector();
        static Vector random(double);
        Vector(double, double);
        Vector(Point, Point);
        double getX();
        double getY();
        void setX(double);
        void setY(double);

        Vector operator*(double);
        Vector operator*=(double);

        Vector operator-(double);
        Vector operator-=(double);
    private:
        double deltaX;
        double deltaY;
};

}

#endif // JESH_VECTOR_H_

