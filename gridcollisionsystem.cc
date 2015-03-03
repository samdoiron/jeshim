#include "gridcollisionsystem.hh"

namespace jesh {
GridCollisionSystem::GridCollisionSystem(int theNumInRow, Dimensions theBounds) :
    bounds(theBounds) {
    Dimensions squareDimensions(
            theBounds.getWidth() / theNumInRow,
            theBounds.getHeight() / theNumInRow
    );
    for (int i = 0; i < theNumInRow * theNumInRow; i++) {
        CollisionSquare square(*this, squareDimensions);
        square.setPosition(Point(
                (i / theNumInRow) * squareDimensions.getWidth(), 
                (i % theNumInRow) * squareDimensions.getHeight()
        ));
        squares.push_back(square);
    }
}

void GridCollisionSystem::addCollidable(Collidable *theCollidable) {
    for (CollisionSquare square : squares) {
        if (square.isCollidingWith(*theCollidable)) {
            square.addCollidable(theCollidable);
        }
    }
}

void GridCollisionSystem::checkCollisions() {
    updateGrid();
    for (CollisionSquare square : squares) {
        square.checkCollisions();
    }
}


// private

void GridCollisionSystem::updateGrid() {
    for (CollisionSquare square : squares) {
        square.update();
    }
}


// === CollisionSquare

CollisionSquare::CollisionSquare(GridCollisionSystem &_parent, Dimensions _bounds) :
    parent(_parent),
    Collidable(_bounds) {
}

/**
 * Remove all collidables from square storage, and reinsert them into
 * the collision system.
 */
void CollisionSquare::update() {
    for (size_t i = 0; i < collidables.size(); i++) {
        Collidable *collidable = collidables[i];
        collidables.erase(collidables.begin() + i);
        parent.addCollidable(collidable);
    }
}

void CollisionSquare::addCollidable(Collidable *theCollidable) {
    collidables.push_back(theCollidable);
}

void CollisionSquare::checkCollisions() {
    for (size_t i = 0; i < collidables.size(); i++) {
        Collidable *colOne = collidables[i];
        for (size_t j = i + 1; j < collidables.size(); j++) {
            Collidable *colTwo = collidables[j];
            if (colOne->isCollidingWith(*colTwo)) {
                colOne->sendCollision(*colTwo);
                colTwo->sendCollision(*colOne);
            }
        }
    }
}


}

