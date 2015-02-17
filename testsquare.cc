#include "testsquare.hh"
#include "dimensions.hh"
#include "eventemitter.hh"
#include "mousemoveevent.hh"
#include "eventtype.hh"
#include "vector.hh"

#include <iostream>

namespace jesh {

TestSquare::TestSquare(EventEmitter &_emitter, bool _followMouse) :
    Entity(Dimensions(128, 128)),
    emitter(_emitter),
    isFollowingMouse(_followMouse) {
    if (isFollowingMouse) {
        emitter.addListener(kMouseMove, *this);
    } else {
        // setFixed();
    }
}

void TestSquare::advance(double) {
    isHit = false;
}

void TestSquare::handleCollision(Collidable&) {
    isHit = true;
}

void TestSquare::handleEvent(MouseMoveEvent &event) {
    position = event.getPosition() + Vector(-64, -64);
}

void TestSquare::sendCollision(Collidable &other) {
    other.handleCollision(*this);
}


}
