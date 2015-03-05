#include "gridcollisionsystem.hh"
#include "debugutils.hh"
#include <iostream>

namespace jesh {
GridCollisionSystem::GridCollisionSystem(int theNumInRow, Dimensions theBounds) :
    bounds(theBounds) {
    Dimensions squareDimensions(
            theBounds.getWidth() / theNumInRow,
            theBounds.getHeight() / theNumInRow
    );
    for (int i = 0; i < theNumInRow * theNumInRow; i++) {
        CollisionSquare square(*this, squareDimensions);
        square.setTopLeft(Point(
            (i / theNumInRow) * squareDimensions.getWidth(), 
            (i % theNumInRow) * squareDimensions.getHeight()
        ));
        squares.push_back(square);
    }
}

void GridCollisionSystem::addCollidable(Collidable *theCollidable) {
    allCollidables.push_back(theCollidable);
    insertIntoSquares(theCollidable);
}

void GridCollisionSystem::checkCollisions() {
    clearGrid();
    reinsertAll();
    checkGridCollisions();
}

// private

void GridCollisionSystem::reinsertAll() {
    for (Collidable *eachCollidable : allCollidables) {
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
        square.clear();
    }
}

// === CollisionSquare

CollisionSquare::CollisionSquare(GridCollisionSystem &_parent, Dimensions _bounds) :
    Rectangle(_bounds),
    parent(_parent) {
}

/**
 * Remove all collidables from square storage, and reinsert them into
 * the collision system.
 */
void CollisionSquare::clear() {
    collidables.clear();
}

void CollisionSquare::addCollidable(Collidable *theCollidable) {
    collidables.push_back(theCollidable);
}

void CollisionSquare::checkCollisions() {
    Debug::getInstance().drawOutlineRect(*this);
    // Brute force through collidables that are in the square.
    for (size_t i = 0; i < collidables.size(); i++) {
        Collidable *colOne = collidables[i];
        for (size_t j = i + 1; j < collidables.size(); j++) {
            Collidable *colTwo = collidables[j];
            if (colOne->isCollidingWith(*colTwo)) {
                resolveCollision(*colOne, *colTwo);
            }
        }
    }
}

}

