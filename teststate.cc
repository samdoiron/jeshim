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
    runningTime(0),
    currentLevel(player, _emitter, "test.jesh"),
    debugSurface(Dimensions(800, 600)),
    levelView(currentLevel) {
    Debug::getInstance().setSurface(&debugSurface);
    updateCamera();
}

void TestState::advance(double secondsPassed) {
    currentLevel.advance(secondsPassed);
    updateCamera();
    render();
}

// === private

void TestState::updateCamera() {
    surface.setOrigin(player.getMiddle());
}

void TestState::render() {
    levelView.renderTo(surface);
    surface.render(debugSurface.asSprite());
}

}
