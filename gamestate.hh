#ifndef JESH_GAMESTATE_H_
#define JESH_GAMESTATE_H_

#include "eventemitter.hh"
#include "rendersurface.hh"

namespace jesh {

/* abstract */ class GameState {
    public:
        GameState(EventEmitter*, RenderSurface*);
        virtual ~GameState();

        // Advance the game a given number of seconds
        virtual void advance(float) = 0;

    protected:
        EventEmitter *emitter;
        RenderSurface *surface;

    private:
        virtual void anchor();
};
    
}

#endif // JESH_GAMESTATE_H_
