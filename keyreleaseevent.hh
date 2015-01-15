#ifndef JESH_KEYRELEASEEVENT_H_
#define JESH_KEYRELEASEEVENT_H_

#include "event.hh"
#include "keycode.hh"
#include "eventlistener.hh"

namespace jesh {

class KeyReleaseEvent : public Event {
    public:
        KeyReleaseEvent(KeyCode);
        KeyCode getKeyCode();
        void sendTo(EventListener&);
    private: 
        KeyCode keyCode;
};

}

#endif // JESH_KEYRELEASEVENT_H_
