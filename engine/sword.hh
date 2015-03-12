#ifndef JESH_SWORD_H_
#define JESH_SWORD_H_

#include "physics/collidable.hh"
#include "entity.hh"
#include "swordview.hh"

namespace jesh {

class Sword : public Entity {
    friend class SwordView;

    public:
        Sword();
        virtual ~Sword() {}
        void advance(double) override;
        void sendCollision(Collidable&) override;
        int getDamage();
        void swing(double);

    private:
        SwordView view;
        double timeSinceSwing;
        double timeToSwing;
        bool isSwinging;
};

}

#endif // JESH_SWORD_H_


