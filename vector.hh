#ifndef JESH_VECTOR_H_
#define JESH_VECTOR_H_

namespace jesh {

class Vector {
    public:
        Vector();
        Vector(double, double);
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

