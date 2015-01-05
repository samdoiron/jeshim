#ifndef JESH_EVENT_H_
#define JESH_EVENT_H_

#include "eventtype.hh"

namespace jesh {

// Serves as a common ancestor so that EventListeners can 
// handle arbitrary (unknown) events.
class Event {
    public:
        Event(EventType);
        EventType getType();
        virtual ~Event();
    private:
        virtual void anchor();
        EventType type;
};

}

#endif // JESH_EVENT_H_
