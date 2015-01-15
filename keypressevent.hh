
#ifndef JESH_KEYPRESSEVENT_H_
#define JESH_KEYPRESSEVENT_H_

#include "event.hh"
#include "keycode.hh"
#include "eventlistener.hh"

namespace jesh {

class EventListener;

class KeyPressEvent : public Event {
    public:
        KeyPressEvent(KeyCode);
        KeyCode getKeyCode();
        void sendTo(EventListener&);
    private: 
        KeyCode keyCode;
};

}

#endif // JESH_KEYPRESSEVENT_H_

