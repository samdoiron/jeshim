#include "event.hh"

#include "eventtype.hh"

namespace jesh {

Event::Event(EventType _type) :
    type(_type) {
}

EventType Event::getType() {
    return this->type;
}

}


