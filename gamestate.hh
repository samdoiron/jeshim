#ifndef JESH_GAMESTATE_H_
#define JESH_GAMESTATE_H_

namespace jesh {

/* abstract */ class GameState {
    public:
        // Advance the game a given number of seconds
        virtual void advance(float) = 0;
    private:
        virtual void anchor();
};
    
}

#endif // JESH_GAMESTATE_H_
