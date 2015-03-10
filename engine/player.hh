#ifndef JESH_PLAYER_H_
#define JESH_PLAYER_H_

#include "geometry/vector.hh"
#include "enemy.hh"
#include "slime.hh"
#include "playerview.hh"

#include "entity.hh"

namespace jesh {

class Player : public Entity {
    friend class PlayerView;
    public:
        Player();
        ~Player();

        // via Entity
        void advance(double);
        void handleCollision(Enemy&);
        void sendCollision(Collidable&);

    private:
        void knockbackFrom(Collidable&);
        void readKeyboard();
        void checkPulse();
        int health;
        double timeSinceKnockback;
        bool isKnockedBack;
        Vector currentKnockback;
        Vector velocity;
        PlayerView view;
};

}


#endif
