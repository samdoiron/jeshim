#ifndef JESH_SLIME_H_
#define JESH_SLIME_H_

#include "physics/collidable.hh"
#include "enemy.hh"
#include "enemyview.hh"
#include "tile.hh"

namespace jesh {

class Level;

class Slime : public Enemy {
    public:
        Slime(Level&);
        virtual void advance(double);
        virtual void handleCollision(Slime&);
        virtual void sendCollision(Collidable&);
        virtual void takeDamage(Point, int) override;
        virtual ~Slime() {}
    private:
        void setRandomVelocity();

        Level &currentLevel;
        EnemyView view;
        bool isKnockedBack;
        double moveSpeed;
        double timeRunning;
        double timeSinceKnockback;
        Vector velocity;
        Vector currentKnockback;
};

}

#endif // JESH_SLIME_H_


