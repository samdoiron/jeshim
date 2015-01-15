#ifndef JESH_POINT_H_
#define JESH_POINT_H_

#include "vector.hh"

namespace jesh {

class Point {
    public:
        Point(double, double);
        double getX();
        double getY();
        void moveRelative(double x, double y);
        void moveRelative(Vector);
    private:
        double x, y;
};

}

#endif // JESH_POINT_H_

