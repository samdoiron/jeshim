#ifndef JESH_ENEMY_H_
#define JESH_ENEMY_H_

#include "dimensions.hh"
#include "entity.hh"
#include "view.hh"

namespace jesh {

/* abstract */ class Enemy : public Entity {
    public:
        Enemy(View&, Dimensions);
        virtual void sendCollision(Collidable&) override;
};

}

#endif // JESH_ENEMY_H_

