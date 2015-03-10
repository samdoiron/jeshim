#include "game.hh"

#include "util/exceptions.hh"
#include "geometry/dimensions.hh"

#include "gamestate.hh"

#include <iostream>
#include <chrono>

namespace jesh {

const double kMaxFrameDifference = 1.0 / 20;

// UGLY: game must have a pointer to state because it needs to bootstrap
// without one, because GameState needs a reference to state.

// A potential fix to this would be to give GameState two methods, isCurrent()
// and getNextState(), which game would poll.

Game::Game(sf::RenderWindow &theWindow) :
    window(theWindow),
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

    sf::View view = window.getView();
    window.setView(view);
    window.setVerticalSyncEnabled(true);

    while (window.isOpen()) {
        // Oh man, working with times sure is fun.
        chrono::steady_clock::time_point now = chrono::steady_clock::now();
        double frameDifference = chrono::duration_cast<chrono::duration<double>>(now - lastUpdate).count();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return;
            } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                return;
            }
        }

        window.clear(sf::Color::Black);

        while (frameDifference > 0) {
            state->advance(std::min(frameDifference, kMaxFrameDifference));
            window.display();
            frameDifference -= kMaxFrameDifference;
        }


        lastUpdate = now;
    }
}

void Game::setState(GameState *_state) {
    this->state = _state;
}

}
