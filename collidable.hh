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

protected:
  void setFixed();
  void setNotFixed();

  Dimensions dimensions;
  Point position;
  bool fixed;

private:
  Point topLeft();
  Point topRight();
  Point bottomLeft();
  Point bottomRight();
};

}

#endif // COLLIDABLE_H_
