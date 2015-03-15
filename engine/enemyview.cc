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
    sf::RectangleShape rect;
    rect.setFillColor(sf::Color::Red);
    rect.setSize(sf::Vector2f(
        enemy.dimensions.getWidth(),
        enemy.dimensions.getHeight()
    ));
    sprite.setPosition(
        static_cast<float>(position.getX()),
        static_cast<float>(position.getY())
    );
    rect.setPosition(
        static_cast<float>(position.getX()),
        static_cast<float>(position.getY())
    );

    if (!enemy.isDead()) {
        theTarget.draw(rect, theStates);
        theTarget.draw(sprite, theStates);
    }
}

}

