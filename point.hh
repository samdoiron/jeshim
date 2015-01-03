#ifndef JESH_POINT_H_
#define JESH_POINT_H_

namespace jesh {

class Point {
    public:
        Point(float, float);
        float getX();
        float getY();
    private:
        float x, y;
};

}

#endif // JESH_POINT_H_

