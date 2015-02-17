#include "basiccollisionsystem.hh"

#include <memory>
#include "collidable.hh"

#include <iostream>

namespace jesh {

void BasicCollisionSystem::addCollidable(Collidable *toAdd) {
  collidables.push_back(toAdd);
}

// DUMB DUMB DUMB XXX XXX TODO:SPEED
// O(n^2) collisions.
void BasicCollisionSystem::checkCollisions() {
  for (size_t i = 0; i < collidables.size(); i++) {
    for (size_t j = i; j < collidables.size(); j++) {
      Collidable *firstCol  = collidables[i];
      Collidable *secondCol = collidables[j];
      if (firstCol->isCollidingWith(*secondCol)) {
        resolveCollision(*firstCol, *secondCol);
      }
    }
  }
}

// private

void BasicCollisionSystem::resolveCollision(
  Collidable &firstCol,
  Collidable &secondCol
) {
  std::cout << "Collision oh yeah!" << std::endl;
  if (firstCol.isFixed() && secondCol.isFixed()) {
    // What happens when an unstoppable force meets an immovable object?
    // Nothing.
  } else if (firstCol.isFixed()) {
    collideFixedAndDynamic(firstCol, secondCol);
  } else if (secondCol.isFixed()) {
    collideFixedAndDynamic(secondCol, firstCol);
  } else {
    collideDynamics(firstCol, secondCol);
  }

  firstCol.sendCollision(secondCol);
  secondCol.sendCollision(firstCol);
}

void BasicCollisionSystem::collideFixedAndDynamic(
  Collidable &fixed,
  Collidable &dynamic
) {
  // In this case the dynamic collidable needs to be moved to the border of
  // the fixed collidable.

  // TODO:CLEAN DEMETER
  // double fixedXMiddle = fixed.getPosition().getX() + (fixed.getDimensions().getWidth() / 2);
  // double fixedYMiddle = fixed.getPosition().getY() + (fixed.getDimensions().getHeight() / 2);
  // XXX Incomplete. Always assumes left collision.

  std::cout << "Collision~!" << std::endl;
  dynamic.setPosition(Point(
    fixed.getPosition().getX() + fixed.getDimensions().getWidth(),
    dynamic.getPosition().getY()
  ));
}

void BasicCollisionSystem::collideDynamics(
  Collidable &firstCol,
  Collidable &secondCol
) {
  // TODO
  throw std::runtime_error("UNIMPLEMENTED: dynamic collision");
}


}
