#ifndef JESH_VECTOR_H_
#define JESH_VECTOR_H_

#include "point.hh"
#include "direction.hh"

namespace jesh {

class Point;

class Vector {
    public:
        Vector();
        static Vector random(double);
        static Vector inDirection(Direction, double);

        Vector(double, double);
        Vector(Point, Point);
        double getX() const;
        double getY() const;
        void setX(double);
        void setY(double);

        Vector withMagnitude(double) const;

        Vector operator*(double) const;
        Vector operator*=(double);

        Vector operator-(double) const;
        Vector operator-=(double);

        Vector operator+(Vector) const;
        Vector operator+=(Vector);

        void setMagnitude(double);
        double getMagnitude() const;
    private:
        double deltaX;
        double deltaY;
};

}

#endif // JESH_VECTOR_H_

