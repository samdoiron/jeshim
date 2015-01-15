#include "keypressevent.hh"
#include "eventtype.hh"
#include "keycode.hh"

#include "eventlistener.hh"

namespace jesh {

KeyPressEvent::KeyPressEvent(KeyCode _keyCode) :
        Event(kKeyPress),
        keyCode(_keyCode) {
}

KeyCode KeyPressEvent::getKeyCode() {
    return keyCode;
}

// Visitor pattern implementation.
void KeyPressEvent::sendTo(EventListener &listener) {
    listener.handleEvent(*this);
}


}

