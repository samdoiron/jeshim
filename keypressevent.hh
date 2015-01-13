
#ifndef JESH_KEYPRESSEVENT_H_
#define JESH_KEYPRESSEVENT_H_

#include "event.hh"
#include "keycode.hh"

namespace jesh {

class KeyPressEvent : public Event {
    public:
        KeyPressEvent(KeyCode);
        KeyCode getKeyCode();
    private: 
        KeyCode keyCode;
};

}

#endif // JESH_KEYPRESSEVENT_H_

