#include "basiccollisionsystem.hh"

#include <memory>
#include "collidable.hh"

#include <iostream>
#include <cmath>

namespace jesh {

void BasicCollisionSystem::addCollidable(Collidable *toAdd) {
  collidables.push_back(toAdd);
}

// DUMB DUMB DUMB XXX XXX TODO:SPEED
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
  double xDepth = std::abs(dynamic.getLeft() - fixed.getLeft());
  double yDepth = std::abs(dynamic.getTop() - fixed.getTop());
  if (xDepth < yDepth) {
      if (dynamic.getYMiddle() > fixed.getYMiddle()) {
          dynamic.setTop(fixed.getBottom());
      } else {
          dynamic.setBottom(fixed.getTop());
      }
  } else {
      if (dynamic.getXMiddle() > fixed.getXMiddle()) {
          dynamic.setLeft(fixed.getRight());
      } else {
          dynamic.setRight(fixed.getLeft());
      }
  }

}

void BasicCollisionSystem::collideDynamics(
  Collidable &firstCol,
  Collidable &secondCol
) {
  // TODO
}


}
