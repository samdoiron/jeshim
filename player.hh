#ifndef JESH_PLAYER_H_
#define JESH_PLAYER_H_

#include "eventlistener.hh"
#include "eventemitter.hh"
#include "event.hh"
#include "mousemoveevent.hh"

#include "entity.hh"

namespace jesh {

class Player : public Entity, public EventListener {
    public:
        Player(EventEmitter&, Point);

        // via Entity
        void advance(float);

        // via EventListener
        void handleEvent(MouseMoveEvent&);
        void handleEvent(Event&);
    private:
        EventEmitter &emitter;
        float timeRunning;
};

}


#endif
