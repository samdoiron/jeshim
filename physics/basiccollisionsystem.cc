#include "basiccollisionsystem.hh"

#include <memory>
#include "collidable.hh"

#include <iostream>
#include <cmath>

namespace jesh {

void BasicCollisionSystem::addCollidable(Collidable *toAdd) {
  collidables.push_back(toAdd);
}

// O(n^2) collisions.
void BasicCollisionSystem::checkCollisions() {
  for (size_t i = 0; i < collidables.size(); i++) {
    for (size_t j = i + 1; j < collidables.size(); j++) {
      Collidable *firstCol  = collidables[i];
      Collidable *secondCol = collidables[j];
      if (firstCol->isCollidingWith(*secondCol)) {
        resolveCollision(*firstCol, *secondCol);
      }
    }
  }
}

// private



}
