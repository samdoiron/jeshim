#ifndef JESH_VECTOR_H_
#define JESH_VECTOR_H_

namespace jesh {

class Vector {
    public:
        Vector();
        Vector(float, float);
        float getX();
        float getY();
        void setX(float);
        void setY(float);

        Vector operator*(float);
        Vector operator*=(float);

        Vector operator-(float);
        Vector operator-=(float);
    private:
        float deltaX;
        float deltaY;
};

}

#endif // JESH_VECTOR_H_

