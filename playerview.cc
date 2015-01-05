#include "playerview.hh"

#include "player.hh"

namespace jesh {

PlayerView::PlayerView(Player *_player) :
    player(_player),
    playerSprite("guy.png", player->getDimensions(), player->getPosition()) {
}

void PlayerView::renderTo(RenderSurface* surface) {
    surface->render(this->playerSprite);
    // TODO add render surface to player view
}


}

