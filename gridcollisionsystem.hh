#ifndef JESH_GRIDCOLLISIONSYSTEM_H_
#define JESH_GRIDCOLLISIONSYSTEM_H_

#include "collisionsystem.hh"
#include "dimensions.hh"
#include "collidable.hh"


namespace jesh {

class GridCollisionSystem;

class CollisionSquare : public CollisionSystem, public Collidable {
    public:
        CollisionSquare(GridCollisionSystem&, Dimensions);

        // Implement required from Collidable
        // TODO Refactor collidable into rectangle to prevent this.
        void sendCollision(Collidable&) override {};
        void checkCollisions();
        void addCollidable(Collidable*);

        void update();
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
        void updateGrid();
        Dimensions bounds;
        std::vector<CollisionSquare> squares;
};

}

#endif // JESH_GRIDCOLLISIONSYSTEM_H_


