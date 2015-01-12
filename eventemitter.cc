#include "eventemitter.hh"

#include "eventtype.hh"
#include "eventlistener.hh"
#include "event.hh"

#include <vector>

namespace jesh {

EventEmitter::EventEmitter() :
    listeners(kNumEventTypes) {
}

void EventEmitter::addListener(EventType type, EventListener &listener) {
    this->listeners[type].push_back(&listener);
}

void EventEmitter::broadcast(Event &event) {
    std::vector<EventListener*> toBeAlerted = this->listeners[event.getType()];
    for (EventListener *listener : toBeAlerted) {
        event.sendTo(*listener);
    }
}

EventEmitter::~EventEmitter() {
}

}


