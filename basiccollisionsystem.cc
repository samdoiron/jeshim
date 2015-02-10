#include "basiccollisionsystem.hh"

#include <memory>
#include "collidable.hh"

namespace jesh {

typedef std::shared_ptr<Collidable> CollidablePtr;

void BasicCollisionSystem::addCollidable(CollidablePtr toAdd) {
  collidables.push_back(toAdd);
}

// DUMB DUMB DUMB XXX XXX TODO:SPEED
// O(n^2) collisions.
void BasicCollisionSystem::checkCollisions() {
  for (int i = 0; i < collidables.size(); i++) {
    for (int j = i; j < collidables.size(); j++) {
      CollidablePtr firstCol  = collidables[i];
      CollidablePtr secondCol = collidables[j];
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
