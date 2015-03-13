#ifndef JESH_ENEMYVIEW_H_
#define JESH_ENEMYVIEW_H_

#include "enemy.hh"
#include "sprite.hh"
#include <sfml/Graphics.hpp>

namespace jesh {

class EnemyView : public sf::Drawable {
    public:
        EnemyView(Enemy&, sf::Sprite);
        void draw(sf::RenderTarget&, sf::RenderStates) const;

    private:
        Enemy &enemy;
        mutable sf::Sprite sprite;
};

}

#endif // JESH_ENEMYVIEW_H_


