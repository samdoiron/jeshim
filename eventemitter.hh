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

/* abstract */ class EventEmitter {
    public:
        EventEmitter();
        virtual void addListener(EventType, EventListener&);
        virtual ~EventEmitter();

    // This is needed by almost every child of EventEmitter, but we don't
    // want just any random stranger to call it.
    protected:
        void broadcast(Event&);

    private:
        std::vector<std::vector<EventListener*>> listeners;
};

}

#endif // JESH_EVENTEMITTER_H_
