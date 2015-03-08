#include "collisionsystem.hh"

#include <cmath>

namespace jesh {

CollisionSystem::~CollisionSystem() {
}

void CollisionSystem::resolveCollision(
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

void CollisionSystem::collideFixedAndDynamic(
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
        dynamic.setTopLeft(dynamic.getTopLeft() + Vector(deltaX, 0));
    } else {
        dynamic.setTopLeft(dynamic.getTopLeft() + Vector(0, deltaY));
    }
}

void CollisionSystem::collideDynamics(
        Collidable&,
        Collidable&
        ) {
    // TODO
}

}
