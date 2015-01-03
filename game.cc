#include "game.hh"

#include "dimensions.hh"
#include "gamestate.hh"

#include <ctime>

#define GAME_TITLE "Jeshim"
#define GAME_WIDTH 800
#define GAME_HEIGHT 600

namespace jesh {

Game::Game(GameState *startingState) :
    window(GAME_TITLE, Dimensions(GAME_WIDTH, GAME_HEIGHT)),
    state(startingState) {
}

void Game::run() {
    time_t lastUpdate = std::clock();
    while (this->window.isOpen()) {
        time_t now = std::clock();
        float frameDifference = (lastUpdate - now) / CLOCKS_PER_SEC;

        this->state->advance(frameDifference);

        lastUpdate = now;
    }
}

}
