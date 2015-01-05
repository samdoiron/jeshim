#include "gamestate.hh"

#include "eventemitter.hh"
#include "rendersurface.hh"

namespace jesh {

GameState::GameState(EventEmitter *outsideWorld, RenderSurface *gameSurface) :
    emitter(outsideWorld),
    surface(gameSurface) {
}

void GameState::anchor() {
}

GameState::~GameState() {
}

}
