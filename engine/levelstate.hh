#include "gamestate.hh"

#include "engine/player.hh"
#include "engine/playerview.hh"
#include "engine/level.hh"
#include "engine/levelview.hh"
#include "physics/basiccollisionsystem.hh"

namespace jesh {

class LevelState : public GameState {
    public:
        LevelState(Game&, sf::RenderTarget&);

        // via GameState
        void advance(double);

    private:
        sf::RenderTarget &target;
        void updateCamera();
        void render();
        Player player;
        Level currentLevel;
        LevelView levelView;
};

}
