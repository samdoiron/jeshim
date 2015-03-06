#ifndef JESH_GAME_H_
#define JESH_GAME_H_

#include "gamestate.hh"
#include "window.hh"

namespace jesh {

class Game {
    public:
        Game(Window&);
        void run();
        void setState(GameState*);
    private:
        void trackFPS(double);
        Window &window;
        GameState *state;
};

}

#endif // HACK_GAME_H_
