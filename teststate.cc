#include "teststate.hh"

#include "eventemitter.hh"
#include "eventlistener.hh"
#include "eventtype.hh"
#include "point.hh"
#include "player.hh"

#include <iostream>
#include <memory>

namespace jesh {

TestState::TestState(Game &_game, EventEmitter &_emitter, RenderSurface &_surface) :
    GameState(_game, _emitter, _surface),
    player(_emitter),
    playerView(player),
    runningTime(0),
    currentLevel(player, _emitter, "test.jesh"),
    levelView(currentLevel) {
    updateCamera();
}

void TestState::advance(double secondsPassed) {
    currentLevel.advance(secondsPassed);
    updateCamera();
    render();
}

void TestState::updateCamera() {
    surface.setOrigin(player.getMiddle());
}

void TestState::render() {
    levelView.renderTo(surface);
}

}
