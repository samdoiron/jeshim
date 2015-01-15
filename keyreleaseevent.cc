#include "keyreleaseevent.hh"
#include "eventlistener.hh"

#include "keycode.hh"

namespace jesh {

KeyReleaseEvent::KeyReleaseEvent(KeyCode _keyCode) :
        Event(kKeyRelease),
        keyCode(_keyCode) {
}

KeyCode KeyReleaseEvent::getKeyCode() {
    return keyCode;
}

void KeyReleaseEvent::sendTo(EventListener &listener) {
    listener.handleEvent(*this);
}

}
