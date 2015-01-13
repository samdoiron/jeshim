#include "keyreleaseevent.hh"

#include "keycode.hh"

namespace jesh {

KeyReleaseEvent::KeyReleaseEvent(KeyCode _keyCode) :
        Event(kKeyRelease),
        keyCode(_keyCode) {
}

KeyCode KeyReleaseEvent::getKeyCode() {
    return keyCode;
}

}
