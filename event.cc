#include "event.hh"

#include "eventlistener.hh"
#include "eventtype.hh"

namespace jesh {

Event::Event(EventType _type) :
    type(_type) {
}

EventType Event::getType() {
    return this->type;
}

void Event::sendTo(EventListener &listener) {
    listener.handleEvent(*this);
}

void Event::anchor() {
}

Event::~Event() {
}

}


