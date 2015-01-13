#ifndef JESH_EVENTLISTENER_H_
#define JESH_EVENTLISTENER_H_

#include "event.hh"

// Event types
#include "mousemoveevent.hh"
#include "keypressevent.hh"
#include "keyreleaseevent.hh"

namespace jesh {

// Pre-declare because mousemoveevent.hh includes eventlistener.hh.
class MouseMoveEvent;

/* abstract */ class EventListener {
    public:
        virtual void handleEvent(Event&) = 0;
        virtual void handleEvent(MouseMoveEvent&) = 0;
        virtual void handleEvent(KeyPressEvent&) = 0;
        virtual void handleEvent(KeyReleaseEvent&) = 0;
        virtual ~EventListener();

    private:
        virtual void anchor();
};

}

#endif // JESH_EVENTLISTENER_H_
