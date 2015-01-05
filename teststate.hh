#include "gamestate.hh"

#include "eventemitter.hh"
#include "player.hh"
#include "playerview.hh"
#include "rendersurface.hh"

namespace jesh {

class TestState : public GameState {
    public:
        TestState(EventEmitter*, RenderSurface*);
        void addListener(EventType, EventListener*);

        // via GameState
        void advance(float);

    private:
        Player player;
        PlayerView playerView;
        void render();
};

}



