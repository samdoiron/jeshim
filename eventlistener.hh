#ifndef JESH_EVENTLISTENER_H_
#define JESH_EVENTLISTENER_H_

#include "event.hh"

namespace jesh {

/* abstract */ class EventListener {
    public:
        virtual void handleEvent(Event);
    private:
        virtual void anchor();
};

}

#endif // JESH_EVENTLISTENER_H_
