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

void Event::anchor() {
}

Event::~Event() {
}

}
