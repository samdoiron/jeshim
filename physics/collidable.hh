#ifndef JESH_COLLIDABLE_H_
#define JESH_COLLIDABLE_H_

#include "geometry/rectangle.hh"
#include "geometry/point.hh"

namespace jesh {

class Enemy;
class Entity;
class Player;
class Slime;
class Tile;

class Collidable : public Rectangle {
    public:
      Collidable(Rectangle);
      virtual void handleCollision(Collidable&) {}
      virtual void handleCollision(Player&) {}
      virtual void handleCollision(Enemy&) {}
      virtual void handleCollision(Slime&) {}

      virtual void sendCollision(Collidable&) = 0;

      virtual void setPosition(Point);
      virtual Point getPosition();

      bool isCollidingWith(Collidable&);
      bool isFixed();

      Collidable(const Collidable&) = default;
      virtual ~Collidable();

    protected:
      void setFixed();
      void setNotFixed();

      bool fixed;

    private:
};

}

#endif // COLLIDABLE_H_
