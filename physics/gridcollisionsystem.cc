#include "gridcollisionsystem.hh"
#include <iostream>

namespace jesh {

const int kNumDivisions = 8;

GridCollisionSystem::GridCollisionSystem(Dimensions theBounds) :
    bounds(theBounds) {
    setupSquares();
}

GridCollisionSystem::GridCollisionSystem() :
    bounds(0, 0) {
}

void GridCollisionSystem::addCollidable(Collidable *theCollidable) {
    if (theCollidable->isFixed()) {
        fixedCollidables.push_back(theCollidable);
    } else {
        dynamicCollidables.push_back(theCollidable);
    }
    insertIntoSquares(theCollidable);
}

void GridCollisionSystem::checkCollisions() {
    clearGrid();
    reinsertDynamic();
    checkGridCollisions();
}

void GridCollisionSystem::setDimensions(Dimensions theDimensions) {
    bounds = theDimensions;
    setupSquares();
}

// private

void GridCollisionSystem::setupSquares() {
    squares.clear();
    Dimensions squareDimensions(
            bounds.getWidth() / kNumDivisions,
            bounds.getHeight() / kNumDivisions
    );
    for (int i = 0; i < kNumDivisions * kNumDivisions; i++) {
        CollisionSquare square(*this, squareDimensions);
        square.setTopLeft(Point(
            (i / kNumDivisions) * squareDimensions.getWidth(), 
            (i % kNumDivisions) * squareDimensions.getHeight()
        ));
        squares.push_back(square);
    }
}

void GridCollisionSystem::reinsertDynamic() {
    for (Collidable *eachCollidable : dynamicCollidables) {
        insertIntoSquares(eachCollidable);
    }
}

void GridCollisionSystem::checkGridCollisions() {
    for (CollisionSquare &eachSquare : squares) {
        eachSquare.checkCollisions();
    }
}

void GridCollisionSystem::insertIntoSquares(Collidable *theCollidable) {
    for (CollisionSquare &square : squares) {
        if (square.isIntersecting(*theCollidable)) {
            square.addCollidable(theCollidable);
        }
    }
}

void GridCollisionSystem::clearGrid() {
    for (CollisionSquare &square : squares) {
        square.clearDynamic();
    }
}

// === CollisionSquare

CollisionSquare::CollisionSquare(GridCollisionSystem &_parent, Dimensions _bounds) :
    Rectangle(_bounds),
    parent(_parent) {
}

/**
 * Remove all dynamic collidables from square storage.
 */
void CollisionSquare::clearDynamic() {
    dynamicCollidables.clear();
}

void CollisionSquare::addCollidable(Collidable *theCollidable) {
    if (theCollidable->isFixed()) {
        fixedCollidables.push_back(theCollidable);
    } else {
        dynamicCollidables.push_back(theCollidable);
    }
}

void CollisionSquare::checkCollisions() {
    checkFixedCollisions();
    checkDynamicCollisions();
}

void CollisionSquare::checkFixedCollisions() {
    for (Collidable *eachDynamic : dynamicCollidables) {
        for (Collidable *eachFixed : fixedCollidables) {
            if (eachFixed->isCollidingWith(*eachDynamic)) {
                resolveCollision(*eachFixed, *eachDynamic);
            }
        }
    }
}

void CollisionSquare::checkDynamicCollisions() {
    for (size_t i = 0; i < dynamicCollidables.size(); i++) {
        Collidable *dynamicOne = dynamicCollidables[i];
        for (size_t j = i + 1; j < dynamicCollidables.size(); j++) {
            Collidable *dynamicTwo = dynamicCollidables[j];
            if (dynamicOne->isCollidingWith(*dynamicTwo)) {
                resolveCollision(*dynamicOne, *dynamicTwo);
            }
        }
    }
}

}

