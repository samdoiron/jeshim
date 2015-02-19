#include "gamestate.hh"

#include "eventemitter.hh"
#include "player.hh"
#include "playerview.hh"
#include "rendersurface.hh"
#include "level.hh"
#include "levelview.hh"
#include "basiccollisionsystem.hh"

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
        Level currentLevel;
        LevelView levelView;
        BasicCollisionSystem collisions;
        void updateCamera();
        void render();
};

}
