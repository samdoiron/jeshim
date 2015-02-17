#ifndef JESH_BASICCOLLISIONSYSTEM_H_
#define JESH_BASICCOLLISIONSYSTEM_H_

#include "collisionsystem.hh"
#include "collidable.hh"
#include <memory>

namespace jesh {

// AKA StupidCollisionSystem
class BasicCollisionSystem : public CollisionSystem {
public:
    virtual void addCollidable(Collidable*);
    virtual void checkCollisions();
    virtual void collideFixedAndDynamic(Collidable&, Collidable&);
    virtual void collideDynamics(Collidable&, Collidable&);

private:
  virtual void resolveCollision(Collidable&, Collidable&);
  std::vector<Collidable*> collidables;
};

}

#endif // JESH_BASICCOLLISIONSYSTEM_H_
