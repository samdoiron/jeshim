#ifndef JESH_RECTANGLE_H_
#define JESH_RECTANGLE_H_

#include "point.hh"
#include "dimensions.hh"

namespace jesh {

class Rectangle {
    public:
        Rectangle(Dimensions);
        Rectangle(Point, Dimensions);

        bool isIntersecting(Rectangle);


        double getTop();
        double getBottom();
        double getLeft();
        double getRight();

        Dimensions getDimensions();

        Point getMiddle();
        Point getTopLeft();
        Point getTopRight();
        Point getBottomLeft();
        Point getBottomRight();

        double getWidth();
        double getHeight();

        double getXMiddle();
        double getYMiddle();

        void setTopLeft(Point);

        void setLeft(double);
        void setRight(double);
        void setTop(double);
        void setBottom(double);

    protected:
        Point topLeft;
        Dimensions dimensions;

};

}

#endif // JESH_RECTANGLE_H_


