#ifndef JESH_SLIME_H_
#define JESH_SLIME_H_

#include "enemy.hh"
#include "singlespriteview.hh"
#include "collidable.hh"
#include "tile.hh"

namespace jesh {

class Slime : public Enemy {
    public:
        Slime();
        virtual void advance(double);
        virtual void handleCollision(Slime&);
        virtual void sendCollision(Collidable&);
        virtual ~Slime() {}
    private:
        void setRandomVelocity();
        SingleSpriteView view;
        double moveSpeed;
        double timeRunning;
        double timeToRun;
        Vector velocity;
};

}

#endif // JESH_SLIME_H_


