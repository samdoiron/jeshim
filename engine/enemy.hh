#ifndef JESH_ENEMY_H_
#define JESH_ENEMY_H_

#include "geometry/dimensions.hh"
#include "physics/collidable.hh"
#include "entity.hh"

#include <sfml/Graphics.hpp>

namespace jesh {

/* abstract */ class Enemy : public Entity {
    public:
        Enemy(sf::Drawable&, Dimensions);
        virtual void sendCollision(Collidable&) override;
};

}

#endif // JESH_ENEMY_H_

