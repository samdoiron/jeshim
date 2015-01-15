#ifndef JESH_GAMESTATE_H_
#define JESH_GAMESTATE_H_

#include "eventemitter.hh"
#include "rendersurface.hh"

namespace jesh {

// Forward declare Game class
class Game;

/* abstract */ class GameState {
    public:
        GameState(Game&, EventEmitter&, RenderSurface&);
        virtual ~GameState();

        // Advance the game a given number of seconds
        virtual void advance(double) = 0;

    protected:
        Game &game;
        EventEmitter &emitter;
        RenderSurface &surface;

    private:
        virtual void anchor();
};
    
}

#endif // JESH_GAMESTATE_H_
