#include "singlespriteview.hh"
#include "entity.hh"
#include <sfml/Graphics.hpp>

namespace jesh {

SingleSpriteView::SingleSpriteView(Entity &theEntity, sf::Sprite theSprite) :
    entity(theEntity),
    sprite(theSprite) {
}

void SingleSpriteView::draw(
    sf::RenderTarget &theTarget, sf::RenderStates theStates
) const {
    Point entityPosition = entity.getTopLeft();
    sprite.setPosition(
        entityPosition.getX(),
        entityPosition.getY()
    );
    theTarget.draw(sprite);
}
    
}

