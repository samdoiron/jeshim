#include "gamestate.hh"

namespace jesh {

class TestState : public GameState {
    public:
        TestState();

        // via GameState
        void advance(float);
};

}



