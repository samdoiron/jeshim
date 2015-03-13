#include "enemyview.hh"
#include "enemy.hh"

#include <sfml/Graphics.hpp>

namespace jesh {
    
EnemyView::EnemyView(Enemy &theEnemy, sf::Sprite theSprite) :
    enemy(theEnemy),
    sprite(theSprite) {
}

void EnemyView::draw(sf::RenderTarget &theTarget, sf::RenderStates theStates) const {
    Point position = enemy.getPosition();
    sprite.setPosition(
        static_cast<float>(position.getX()),
        static_cast<float>(position.getY())
    );

    if (!enemy.isDead()) {
        theTarget.draw(sprite, theStates);
    }
}

}

