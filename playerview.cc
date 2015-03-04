#include "playerview.hh"

#include <iostream>

#include "player.hh"

namespace jesh {

PlayerView::PlayerView(Player &_player) :
    player(_player),
        playerSprite("guy.png", player.getDimensions(), player.getTopLeft()) {
}

void PlayerView::renderTo(RenderSurface &surface) {
    this->playerSprite.setPosition(this->player.getTopLeft());

    surface.render(this->playerSprite);
    // TODO add render surface to player view
}


}

