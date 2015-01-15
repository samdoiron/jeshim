#include "game.hh"

#include "dimensions.hh"
#include "gamestate.hh"

#include <ctime>
#include <stdexcept>
#include <iostream>

namespace jesh {

// UGLY: game must have a pointer to state because it needs to bootstrap
// without one, because GameState needs a reference to state.

// A potential fix to this would be to give GameState two methods, isCurrent()
// and getNextState(), which game would poll.

Game::Game(Window &_window) :
    window(_window),
    state(nullptr) {
}

void Game::run() {
    clock_t lastUpdate = std::clock();

    // State is pseudo-optional because state needs a reference to the game to
    // be created.
    if (state == nullptr) {
        throw std::runtime_error("Attempt to run game without setting state.");
    }

    while (this->window.isOpen()) {
        clock_t now = std::clock();
        double frameDifference = static_cast<double>(now - lastUpdate) / CLOCKS_PER_SEC;

        this->window.clear();
        this->state->advance(frameDifference);
        this->window.update();

        lastUpdate = now;
    }
}

// TODO Event management should probably be managed somewhere else, Game could
// easily become a god class

void Game::setState(GameState *_state) {
    this->state = _state;
}

}
