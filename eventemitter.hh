#ifndef JESH_EVENTEMITTER_H_
#define JESH_EVENTEMITTER_H_

#include "eventtype.hh"
#include "eventlistener.hh"

#include <vector>

// TODO: This probably should be a template that takes the EventType as
// an parameter.
//
// Eg. EventEmitter<IOEvent>

namespace jesh {

class EventEmitter {
    public:
        EventEmitter();
        void addListener(EventType, EventListener);
        void broadcast(Event);
    private:
        std::vector<std::vector<EventListener>> listeners;
};

}

#endif // JESH_EVENTEMITTER_H_
