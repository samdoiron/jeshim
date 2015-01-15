#ifndef JESH_POINT_H_
#define JESH_POINT_H_

#include "vector.hh"

namespace jesh {

class Point {
    public:
        Point(float, float);
        float getX();
        float getY();
        void moveRelative(float x, float y);
        void moveRelative(Vector);
    private:
        float x, y;
};

}

#endif // JESH_POINT_H_

