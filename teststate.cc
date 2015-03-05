#include "teststate.hh"

#include "debugutils.hh"
#include "eventemitter.hh"
#include "eventlistener.hh"
#include "eventtype.hh"
#include "player.hh"
#include "point.hh"

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
    Debug::getInstance().setSurface(&surface);
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
    Debug &debug = Debug::getInstance();
    levelView.renderTo(surface);
    debug.render();
}

}
