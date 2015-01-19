#include "teststate.hh"

#include "eventemitter.hh"
#include "eventlistener.hh"
#include "eventtype.hh"
#include "point.hh"
#include "player.hh"

#include <iostream>

namespace jesh {

TestState::TestState(Game &_game, EventEmitter &_emitter, RenderSurface &_surface) :
    GameState(_game, _emitter, _surface),
    player(_emitter, Point(100, 100)),
    playerView(player), 
    runningTime(0),
    numTicks(0),
    currentLevel("test.jesh"), 
    levelView(currentLevel) {
    surface.setOrigin(Point(50, 50));
}

void TestState::advance(double difference) {
    trackFramerate(difference);
    player.advance(difference);
    surface.setOrigin(player.getPosition());
    render();
}

void TestState::render() {
    levelView.renderTo(surface);
    playerView.renderTo(surface);
}

void TestState::trackFramerate(double difference) {
    numTicks += 1;
    runningTime += difference;
    if (runningTime > 1) {
        std::cout << "Running at " << numTicks / runningTime << "fps" << std::endl;
        numTicks = 0;
        runningTime = 0;
    }
}

}

