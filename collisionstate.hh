#ifndef JESH_COLLISIONSTATE_H_
#define JESH_COLLISIONSTATE_H_

#include "gamestate.hh"
#include "eventemitter.hh"
#include "rendersurface.hh"
#include "basiccollisionsystem.hh"
#include "testsquare.hh"
#include "testsquareview.hh"

namespace jesh {

class CollisionState : public GameState {
public:
    CollisionState(Game&, EventEmitter&, RenderSurface&);
    virtual void advance(double);
    void render();

private:
    TestSquare squareOne;
    TestSquare squareTwo;
    TestSquareView viewOne;
    TestSquareView viewTwo;
    BasicCollisionSystem collisions;
};

}

#endif // JESH_COLLISION_H_
