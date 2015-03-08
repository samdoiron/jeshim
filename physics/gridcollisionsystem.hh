#ifndef JESH_GRIDCOLLISIONSYSTEM_H_
#define JESH_GRIDCOLLISIONSYSTEM_H_

#include "collisionsystem.hh"
#include "geometry/dimensions.hh"
#include "geometry/rectangle.hh"
#include "collidable.hh"

namespace jesh {

class GridCollisionSystem;

class CollisionSquare : public CollisionSystem, public Rectangle {
    public:
        CollisionSquare(GridCollisionSystem&, Dimensions);

        void checkCollisions();
        void addCollidable(Collidable*);
        void clearDynamic();
    private:
        void checkFixedCollisions();
        void checkDynamicCollisions();
        GridCollisionSystem &parent;
        std::vector<Collidable*> fixedCollidables;
        std::vector<Collidable*> dynamicCollidables;
};


class GridCollisionSystem : public CollisionSystem {
    public:
        GridCollisionSystem();
        GridCollisionSystem(Dimensions);
        virtual void addCollidable(Collidable*);
        virtual void checkCollisions();
        void setDimensions(Dimensions);

    private:
        void setupSquares();
        void clearGrid();
        void checkGridCollisions();
        void reinsertDynamic();
        void insertIntoSquares(Collidable*);
        Dimensions bounds;
        std::vector<CollisionSquare> squares;
        std::vector<Collidable*> dynamicCollidables;
        std::vector<Collidable*> fixedCollidables;
};

}

#endif // JESH_GRIDCOLLISIONSYSTEM_H_


