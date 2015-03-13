#ifndef JESH_SWORD_H_
#define JESH_SWORD_H_

#include "physics/collidable.hh"
#include "geometry/direction.hh"
#include "geometry/point.hh"

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
        void handleCollision(Collidable&) override;
        void handleCollision(Enemy&) override;

        int getDamage() const;
        void swing(Direction, double);
        void setOrigin(Point);
        void setDirection(Direction);

    private:
        void updateDimensions();
        void updatePosition();

        SwordView view;
        Direction facing;
        Vector velocity;
        Point origin;
        double timeSinceSwing;
        double timeToSwing;
        bool isSwinging;
};

}

#endif // JESH_SWORD_H_


