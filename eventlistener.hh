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
class KeyPressEvent;
class KeyReleaseEvent;

class EventListener {
    public:
        virtual void handleEvent(Event&) {}
        virtual void handleEvent(MouseMoveEvent&) {}
        virtual void handleEvent(KeyPressEvent&) {}
        virtual void handleEvent(KeyReleaseEvent&) {}
        virtual ~EventListener();

    private:
        virtual void anchor();
};

}

#endif // JESH_EVENTLISTENER_H_
