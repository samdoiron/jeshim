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
        void advance(double);

    private:
        Player player;
        PlayerView playerView;
        double runningTime;
        int numTicks;
        void render();
        void trackFramerate(double);
};

}



