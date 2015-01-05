#include "mousemoveevent.hh"

#include "eventtype.hh"

namespace jesh {

MouseMoveEvent::MouseMoveEvent(Point point) :
    Event(kMouseMove),
    position(point) {
}

float MouseMoveEvent::getX() {
    return this->position.getX();
}

float MouseMoveEvent::getY() {
    return this->position.getY();
}

void MouseMoveEvent::anchor() {
}

}
