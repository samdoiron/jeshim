#ifndef JESH_EVENT_H_
#define JESH_EVENT_H_

#include "eventtype.hh"

// TODO: This probably should be a template that takes the EventType as
// an parameter.

namespace jesh {

// Serves as a common ancestor so that EventListeners can 
// handle arbitrary (unknown) events.
class Event {
    public:
        Event(EventType);
        virtual EventType getType();
    private:
        EventType type;
};

}

#endif // JESH_EVENT_H_
