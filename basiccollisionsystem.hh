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

private:
  std::vector<Collidable*> collidables;
};

}

#endif // JESH_BASICCOLLISIONSYSTEM_H_
