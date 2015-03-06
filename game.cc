#include "game.hh"

#include "exceptions.hh"
#include "dimensions.hh"
#include "gamestate.hh"

#include <iostream>
#include <chrono>

namespace jesh {

const double kMaxFrameDifference = 1.0 / 20;

// UGLY: game must have a pointer to state because it needs to bootstrap
// without one, because GameState needs a reference to state.

// A potential fix to this would be to give GameState two methods, isCurrent()
// and getNextState(), which game would poll.

Game::Game(Window &_window) :
    window(_window),
    state(nullptr) {
}

void Game::run() {
    namespace chrono = std::chrono;

    chrono::steady_clock::time_point lastUpdate = chrono::steady_clock::now();

    // State is pseudo-optional because state needs a reference to the game to
    // be created.
    if (state == nullptr) {
        throw_error("Attempt to run game without setting state.");
    }

    while (this->window.isOpen()) {
        // Oh man, working with times sure is fun.
        chrono::steady_clock::time_point now = chrono::steady_clock::now();
        double frameDifference = chrono::duration_cast<chrono::duration<double>>(now - lastUpdate).count();
        // trackFPS(frameDifference);

        this->window.clear();
        while (frameDifference > 0) {
            this->state->advance(std::min(frameDifference, kMaxFrameDifference));
            this->window.update();
            frameDifference -= kMaxFrameDifference;
        }

        lastUpdate = now;
    }
}

void Game::trackFPS(double theFrameDifference) {
    std::cout << static_cast<int>(1 / theFrameDifference) << std::endl;;
}

void Game::setState(GameState *_state) {
    this->state = _state;
}

}
