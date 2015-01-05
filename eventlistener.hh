#ifndef JESH_EVENTLISTENER_H_
#define JESH_EVENTLISTENER_H_

#include "event.hh"

namespace jesh {

class EventListener {
    public:
        virtual void handleEvent(Event);
        virtual ~EventListener();
    private:
        virtual void anchor();
};

}

#endif // JESH_EVENTLISTENER_H_
