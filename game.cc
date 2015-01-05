#include "game.hh"

#include "dimensions.hh"
#include "gamestate.hh"

#include <ctime>
#include <stdexcept>

namespace jesh {

Game::Game(Window* _window) :
    window(_window),
    state(NULL) {
}

void Game::run() {
    clock_t lastUpdate = std::clock();

    if (this->state == NULL) {
        throw std::runtime_error("Attempt to run game without setting state.");
    }

    while (this->window->isOpen()) {
        clock_t now = std::clock();
        float frameDifference = (lastUpdate - now) / CLOCKS_PER_SEC;

        this->window->clear();
        this->state->advance(frameDifference);
        this->window->update();

        lastUpdate = now;
    }
}

// TODO Event management should probably be managed somewhere else, Game could
// easily become a god class

void Game::setState(GameState *_state) {
    this->state = _state;
}

}
