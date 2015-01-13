#include "keypressevent.hh"
#include "eventtype.hh"
#include "keycode.hh"

namespace jesh {

KeyPressEvent::KeyPressEvent(KeyCode _keyCode) :
        Event(kKeyPress),
        keyCode(_keyCode) {
}

KeyCode KeyPressEvent::getKeyCode() {
    return keyCode;
}

}

