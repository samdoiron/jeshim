#ifndef JESH_PLAYER_H_
#define JESH_PLAYER_H_

#include "eventlistener.hh"
#include "eventemitter.hh"
#include "event.hh"
#include "mousemoveevent.hh"
#include "keypressevent.hh"
#include "keyreleaseevent.hh"
#include "vector.hh"
#include "enemy.hh"
#include "slime.hh"
#include "playerview.hh"

#include "entity.hh"

namespace jesh {

class Player : public Entity, public EventListener {
    friend class PlayerView;
    public:
        Player(EventEmitter&);
        ~Player();

        // via Entity
        void advance(double);

        // via EventListener
        void handleEvent(KeyPressEvent&);
        void handleEvent(KeyReleaseEvent&);
        void handleEvent(Event&);

        void handleCollision(Enemy&);

        void sendCollision(Collidable&);

    private:
        void knockbackFrom(Collidable&);
        double timeSinceKnockback;
        bool isKnockedBack;
        Vector currentKnockback;
        EventEmitter &emitter;
        Vector velocity;
        PlayerView view;
};

}


#endif
