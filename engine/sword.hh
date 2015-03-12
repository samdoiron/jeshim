#ifndef JESH_SWORD_H_
#define JESH_SWORD_H_

#include "physics/collidable.hh"
#include "entity.hh"

namespace jesh {

class Sword : public Entity {
    public:
        Sword();
        int getDamage();
        void swing(double);
        void advance(double);
        void sendCollision(Collidable&);

    private:
        SwordView view;
        double timeSinceSwing;
        double timeToSwing;
        bool isSwinging;
};

}

#endif // JESH_SWORD_H_


