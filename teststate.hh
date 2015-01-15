#include "gamestate.hh"

#include "eventemitter.hh"
#include "player.hh"
#include "playerview.hh"
#include "rendersurface.hh"

namespace jesh {

class TestState : public GameState {
    public:
        TestState(Game&, EventEmitter&, RenderSurface&);
        void addListener(EventType, EventListener&);

        // via GameState
        void advance(float);

    private:
        Player player;
        PlayerView playerView;
        float runningTime;
        int numTicks;
        void render();
        void trackFramerate(float);
};

}



