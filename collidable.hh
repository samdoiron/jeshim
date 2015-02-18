#ifndef JESH_COLLIDABLE_H_
#define JESH_COLLIDABLE_H_

#include "dimensions.hh"
#include "point.hh"
#include "dimensions.hh"

namespace jesh {

class Collidable {
public:
  Collidable(Dimensions);
  virtual void handleCollision(Collidable&);
  virtual void sendCollision(Collidable&) = 0;

  Point getPosition();
  Dimensions getDimensions();
  void setPosition(Point);
  bool isCollidingWith(Collidable&);
  bool isFixed();

  Collidable(const Collidable&) = default;
  virtual ~Collidable();

  double getTop();
  double getBottom();
  double getLeft();
  double getRight();

  double getWidth();
  double getHeight();

  double getXMiddle();
  double getYMiddle();

  void setXPosition(double);
  void setYPosition(double);
  void setLeft(double);
  void setRight(double);
  void setTop(double);
  void setBottom(double);


protected:
  void setFixed();
  void setNotFixed();

  Dimensions dimensions;
  Point position;
  bool fixed;

private:
};

}

#endif // COLLIDABLE_H_
