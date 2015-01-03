#ifndef HACK_GAMESTATE_H_
#define HACK_GAMESTATE_H_

namespace jesh {

/* abstract */ class GameState {
    public:
        // Advance the game a given number of seconds
        virtual void advance(float) = 0;
    private:
        virtual void anchor();
};
    
}

#endif // HACK_GAMESTATE_H_
