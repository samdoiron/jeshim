#ifndef JESH_GAME_H_
#define JESH_GAME_H_

#include "gamestate.hh"
#include "window.hh"

namespace jesh {

class Game {
    public:
        Game(GameState*);
        void run();
    private:
        GameState *state;
        Window window;
};

}

#endif // HACK_GAME_H_
