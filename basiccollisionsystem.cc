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
  bool toRight = dynamic.getXMiddle() > fixed.getXMiddle();
  bool below = dynamic.getYMiddle() > fixed.getYMiddle();

  double deltaX = 0;
  double deltaY = 0;

  if (toRight) {
      deltaX = fixed.getRight() - dynamic.getLeft();
  } else {
      deltaX = fixed.getLeft() - dynamic.getRight();
  }
  
  if (below) {
      deltaY = fixed.getBottom() - dynamic.getTop();
  } else {
      deltaY = fixed.getTop() - dynamic.getBottom();
  }

  // Assume the smaller adjustment
  if (std::abs(deltaX) < std::abs(deltaY)) {
      dynamic.setPosition(dynamic.getPosition() + Vector(deltaX, 0));
  } else {
      dynamic.setPosition(dynamic.getPosition() + Vector(0, deltaY));
  }
}

void BasicCollisionSystem::collideDynamics(
  Collidable &firstCol,
  Collidable &secondCol
) {
  // TODO
}


}
