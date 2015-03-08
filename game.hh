#ifndef JESH_GAME_H_
#define JESH_GAME_H_

#include "gamestate.hh"
#include <sfml/Graphics.hpp>

namespace jesh {

class Game {
    public:
        Game(sf::RenderWindow &window);
        void run();
        void setState(GameState*);
    private:
        void trackFPS(double);
        sf::RenderWindow &window;
        GameState *state;
};

}

#endif // HACK_GAME_H_
