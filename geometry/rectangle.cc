#include "rectangle.hh"

#include "point.hh"
#include "dimensions.hh"

namespace jesh {

Rectangle::Rectangle(Dimensions theDimensions) :
    topLeft(0, 0),
    dimensions(theDimensions) {
}

Rectangle::Rectangle(Point theTopLeft, Dimensions theDimensions) :
    topLeft(theTopLeft),
    dimensions(theDimensions) {
}

bool Rectangle::isIntersecting(Rectangle other) {
    return (
        getLeft()       <= other.getRight()  &&
        other.getLeft() <= getRight()        &&
        getTop()        <= other.getBottom() &&
        other.getTop()  <= getBottom()
    );
}

double Rectangle::getTop() {
    return topLeft.getY();
}

double Rectangle::getBottom() {
    return getTop() + dimensions.getHeight();
}

double Rectangle::getLeft() {
    return topLeft.getX();
}

double Rectangle::getRight() {
    return getLeft()  + dimensions.getWidth();
}

Dimensions Rectangle::getDimensions() {
    return dimensions;
}

Point Rectangle::getMiddle() {
    return getTopLeft() + Vector(getWidth() / 2, getHeight() / 2);
}

Point Rectangle::getTopLeft() {
    return topLeft;
}

Point Rectangle::getTopRight() {
    return Point(getRight(), getTop());
}

Point Rectangle::getBottomLeft() {
    return Point(getLeft(), getBottom());
}

Point Rectangle::getBottomRight() {
    return Point(getRight(), getBottom());
}

double Rectangle::getWidth() {
    return dimensions.getWidth();
}

double Rectangle::getXMiddle() {
    return topLeft.getX() + dimensions.getWidth() / 2;
}

double Rectangle::getYMiddle() {
    return topLeft.getY() + dimensions.getHeight() / 2;
}

double Rectangle::getHeight() {
    return dimensions.getHeight();
}

void Rectangle::setTopLeft(Point newTopLeft) {
  topLeft = newTopLeft;
}

void Rectangle::setLeft(double newLeft) {
    topLeft.setX(newLeft);
}

void Rectangle::setRight(double newRight) {
    topLeft.setX(topLeft.getX() + (newRight - getRight()));
}

void Rectangle::setTop(double newTop) {
    topLeft.setY(newTop);
}

void Rectangle::setBottom(double newBottom) {
    topLeft.setY(topLeft.getY() + (newBottom - getBottom()));
}

void Rectangle::moveRelative(Vector theVector) {
    topLeft += theVector;
}
    
}

