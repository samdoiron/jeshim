#include "event.hh"

#include "eventlistener.hh"
#include "eventtype.hh"

#include <stdexcept>

namespace jesh {

Event::Event(EventType _type) :
    type(_type) {
}

EventType Event::getType() {
    return this->type;
}

void Event::sendTo(EventListener&) {
    throw std::runtime_error("Event must override sendTo()");
}

void Event::anchor() {
}

Event::~Event() {
}

}


