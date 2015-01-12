#include "mousemoveevent.hh"

#include "eventtype.hh"

#include <iostream>

namespace jesh {

MouseMoveEvent::MouseMoveEvent(Point point) :
    Event(kMouseMove),
    position(point) {
}

Point MouseMoveEvent::getPosition() {
    return position;
}

void MouseMoveEvent::sendTo(EventListener &listener) {
    listener.handleEvent(*this);
}

void MouseMoveEvent::anchor() {
}

}
