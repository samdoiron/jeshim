#ifndef JESH_TESTSQUARE_H_
#define JESH_TESTSQUARE_H_

#include "collidable.hh"
#include "entity.hh"
#include "testsquare.hh"
#include "eventemitter.hh"
#include "mousemoveevent.hh"
#include "eventlistener.hh"

namespace jesh {

class TestSquare : public Entity, public EventListener {

friend class TestSquareView;

public:
    TestSquare(EventEmitter&, bool);
    virtual void advance(double);

    void handleCollision(Collidable&);
    void sendCollision(Collidable&);

    void handleEvent(MouseMoveEvent&);

private:
    EventEmitter &emitter;
    bool isHit;
    bool isFollowingMouse;
};

}

#endif // JESH_TESTSQUARE_H_
