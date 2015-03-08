#ifndef JESH_GAMESTATE_H_
#define JESH_GAMESTATE_H_

#include <sfml/Graphics.hpp>

// Forawrd declare game.

namespace jesh {

class Game;

/* abstract */ class GameState {
    public:
        GameState(Game&, sf::RenderTarget&);
        virtual ~GameState();

        // Advance the game a given number of seconds
        virtual void advance(double) = 0;

    protected:
        Game &game;
        sf::RenderTarget &target;

    private:
        virtual void anchor();
};
    
}

#endif // JESH_GAMESTATE_H_
