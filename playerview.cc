#include "playerview.hh"

#include <iostream>

#include "player.hh"

namespace jesh {

PlayerView::PlayerView(Player &_player) :
    frameNumber(0),
    player(_player),
    upSprite("img/link-up.png", player.getDimensions(), player.getTopLeft()),
    rightSprite("img/link-right.png", player.getDimensions(), player.getTopLeft()),
    leftSprite("img/link-left.png", player.getDimensions(), player.getTopLeft()),
    downSprite("img/link-down.png", player.getDimensions(), player.getTopLeft()),
    currentSprite(&downSprite) {
}

void PlayerView::renderTo(RenderSurface &surface) {
    // Run right
    if (player.velocity.getX() > 0) {
        currentSprite = &rightSprite;
    // Run left
    } else if (player.velocity.getX() < 0) {
        currentSprite = &leftSprite;
    // Run down
    } else if (player.velocity.getY() > 0) {
        currentSprite = &downSprite;
    // Run up
    } else if (player.velocity.getY() < 0) {
        currentSprite = &upSprite;
    }
    currentSprite->setPosition(this->player.getTopLeft());
    surface.render(*this->currentSprite);
}

}

