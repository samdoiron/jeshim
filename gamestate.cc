#include "gamestate.hh"
#include "game.hh"
#include <sfml/Graphics.hpp>

namespace jesh {

GameState::GameState(Game &theGame, sf::RenderTarget &theTarget) :
    game(theGame),
    target(theTarget) {
}

void GameState::anchor() {
}

GameState::~GameState() {
}

}
