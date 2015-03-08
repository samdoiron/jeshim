#include "playerview.hh"

#include <iostream>

#include "player.hh"

namespace jesh {

PlayerView::PlayerView(Player &_player) :
    player(_player),
    sprite(Sprite::get(Sprite::kPlayer)) {
}

// Update internal state to match that of the tracked entity
// (eg. Move the sprite to the entity's position). 
// This can't be done in draw because it needs to be const.
void PlayerView::update() {
}

void PlayerView::draw(sf::RenderTarget &theTarget, sf::RenderStates theStates) const {
    Point position = player.getTopLeft();
    int newX = position.getX();
    int newY = position.getY();
    sprite.setPosition(newX, newY);
    theTarget.draw(sprite, theStates);
}

}

