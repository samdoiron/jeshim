#include "teststate.hh"

#include "eventemitter.hh"
#include "eventlistener.hh"
#include "eventtype.hh"

#include "player.hh"

#include <iostream>

namespace jesh {

TestState::TestState(Game &_game, EventEmitter &_emitter, RenderSurface &_surface) :
    GameState(_game, _emitter, _surface),
    player(_emitter, Point(100, 100)),
    playerView(player), 
    runningTime(0),
    numTicks(0) {
}

void TestState::advance(float difference) {
    this->trackFramerate(difference);
    this->player.advance(difference);
    this->render();
}

void TestState::render() {
    playerView.renderTo(this->surface);
}

void TestState::trackFramerate(float difference) {
    this->numTicks += 1;
    this->runningTime += difference;
    if (this->runningTime > 1) {
        std::cout << "Running at " << this->numTicks / this->runningTime << "fps" << std::endl;
        this->numTicks = 0;
        this->runningTime = 0;
        }
    }
}

