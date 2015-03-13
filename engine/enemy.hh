#ifndef JESH_ENEMY_H_
#define JESH_ENEMY_H_

#include "geometry/dimensions.hh"
#include "physics/collidable.hh"
#include "entity.hh"

#include <sfml/Graphics.hpp>

namespace jesh {

/* abstract */ class Enemy : public Entity {
    friend class EnemyView;
    public:
        Enemy(sf::Drawable&, Dimensions, int);
        virtual void takeDamage(Point, int);
        virtual void sendCollision(Collidable&) override;

    protected:
        bool isDead();

    private:
        int health;
};

}

#endif // JESH_ENEMY_H_

