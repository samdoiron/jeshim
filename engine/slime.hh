#ifndef JESH_SLIME_H_
#define JESH_SLIME_H_

#include "physics/collidable.hh"
#include "enemy.hh"
#include "enemyview.hh"
#include "tile.hh"

namespace jesh {

class Slime : public Enemy {
    public:
        Slime();
        virtual void advance(double);
        virtual void handleCollision(Slime&);
        virtual void sendCollision(Collidable&);
        virtual void takeDamage(Point, int) override;
        virtual ~Slime() {}
    private:
        void setRandomVelocity();
        bool isKnockedBack;
        EnemyView view;
        double moveSpeed;
        double timeRunning;
        Vector velocity;
        Vector currentKnockback;
};

}

#endif // JESH_SLIME_H_


