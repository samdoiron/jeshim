#ifndef JESH_GRIDCOLLISIONSYSTEM_H_
#define JESH_GRIDCOLLISIONSYSTEM_H_

#include "collisionsystem.hh"
#include "dimensions.hh"
#include "collidable.hh"
#include "rectangle.hh"


namespace jesh {

class GridCollisionSystem;

class CollisionSquare : public CollisionSystem, public Rectangle {
    public:
        CollisionSquare(GridCollisionSystem&, Dimensions);

        void checkCollisions();
        void addCollidable(Collidable*);
        void clear();
    private:
        GridCollisionSystem &parent;
        std::vector<Collidable*> collidables;
};


class GridCollisionSystem : public CollisionSystem {
    public:
        GridCollisionSystem(int, Dimensions);
        virtual void addCollidable(Collidable*);
        virtual void checkCollisions();
    private:
        void clearGrid();
        void checkGridCollisions();
        void reinsertAll();
        void insertIntoSquares(Collidable*);
        Dimensions bounds;
        std::vector<CollisionSquare> squares;
        std::vector<Collidable*> allCollidables;
};

}

#endif // JESH_GRIDCOLLISIONSYSTEM_H_


