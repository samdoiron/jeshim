#ifndef JESH_COLLISIONSYSTEM_H_
#define JESH_COLLISIONSYSTEM_H_

#include "collidable.hh"
#include <memory>

namespace jesh {

/* abstract */ class CollisionSystem {
public:
  virtual void addCollidable(std::shared_ptr<Collidable>) = 0;
  virtual void checkCollisions() = 0;
  virtual void anchor();
};

}

#endif // JESH_COLLISIONSYSTEM_H_
