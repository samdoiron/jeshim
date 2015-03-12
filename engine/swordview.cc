#include "swordview.hh"
#include "sprite.hh"
#include "geometry/point.hh"

namespace jesh {

SwordView::SwordView(Sword &theSword) :
    sword(theSword),
    swordSprite(Sprite::get(Sprite::kSword)) {
}

void SwordView::draw(sf::RenderTarget &theTarget, sf::RenderStates theStates) const {
    swordSprite.setPosition(
        static_cast<float>(10),
        static_cast<float>(10)
    );
    theTarget.draw(swordSprite, theStates);
}
    
}

