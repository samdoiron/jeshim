#ifndef JESH_COLLISIONSYSTEM_H_
#define JESH_COLLISIONSYSTEM_H_

#include "collidable.hh"
#include <memory>

namespace jesh {


/*
 * CollisionSystem does not free any of it's tracked items!
 */

/* abstract */ class CollisionSystem {
    public:
      virtual void addCollidable(Collidable*) = 0;
      virtual void removeCollidable(Collidable*) = 0;
      virtual void checkCollisions() = 0;
      virtual ~CollisionSystem();

    protected:
      void resolveCollision(Collidable&, Collidable&);

    private:
      void collideFixedAndDynamic(Collidable&, Collidable&);
      void collideDynamics(Collidable&, Collidable&);
};

}

#endif // JESH_COLLISIONSYSTEM_H_
