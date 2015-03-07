#include "gamestate.hh"

#include "eventemitter.hh"
#include "player.hh"
#include "playerview.hh"
#include "rendersurface.hh"
#include "level.hh"
#include "levelview.hh"
#include "basiccollisionsystem.hh"
#include "spritesurface.hh"

namespace jesh {

class TestState : public GameState {
    public:
        TestState(Game&, EventEmitter&, RenderSurface&);
        void addListener(EventType, EventListener&);

        // via GameState
        void advance(double);

    private:
        void updateCamera();
        void render();
        SpriteSurface debugSurface;
        Player player;
        double runningTime;
        Level currentLevel;
        LevelView levelView;
        BasicCollisionSystem collisions;
};

}
