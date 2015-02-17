#include "teststate.hh"

#include "eventemitter.hh"
#include "eventlistener.hh"
#include "eventtype.hh"
#include "point.hh"
#include "player.hh"

#include <iostream>
#include <memory>

namespace jesh {

const double kCameraRadius = 100;

TestState::TestState(Game &_game, EventEmitter &_emitter, RenderSurface &_surface) :
    GameState(_game, _emitter, _surface),
    player(_emitter),
    playerView(player),
    runningTime(0),
    currentLevel(player, _emitter, "test.jesh"),
    levelView(currentLevel) {
  surface.setOrigin(player.getPosition());
}

void TestState::advance(double secondsPassed) {
    Point oldPlayerPosition = player.getPosition();
    currentLevel.advance(secondsPassed);
    Point newPlayerPosition = player.getPosition();

    Vector playerDelta(oldPlayerPosition, newPlayerPosition);

    // TODO:CLEAN I don't think camera logic should go here...

    Point cameraPosition = surface.getOrigin();

    if (newPlayerPosition.distanceTo(cameraPosition) > kCameraRadius) {
        surface.setOrigin(cameraPosition + playerDelta);
    }


    render();
}

void TestState::render() {
    levelView.renderTo(surface);
}

}
