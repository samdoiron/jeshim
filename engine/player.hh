#ifndef JESH_PLAYER_H_
#define JESH_PLAYER_H_

#include "geometry/direction.hh"
#include "geometry/vector.hh"

#include "enemy.hh"
#include "slime.hh"
#include "playerview.hh"
#include "sword.hh"

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
        Sword &getSword();

    private:
        void knockbackFrom(Collidable&);
        void readKeyboard();
        void checkPulse();
        void swingSword();
        void updateFacing();
        void updateSword(double);
        void applyKnockback(double);
        void move(double);

        int health;
        Sword sword;
        double timeSinceKnockback;
        bool isKnockedBack;
        bool swungLastFrame;
        Vector currentKnockback;
        Vector velocity;
        Direction facing;
        PlayerView view;
};

}


#endif
