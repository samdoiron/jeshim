#include "gamestate.hh"

#include "eventemitter.hh"
#include "rendersurface.hh"

namespace jesh {

GameState::GameState(Game &_game, EventEmitter &outsideWorld, RenderSurface &gameSurface) :
    game(_game),
    emitter(outsideWorld),
    surface(gameSurface) {
}

void GameState::anchor() {
}

GameState::~GameState() {
}

}
