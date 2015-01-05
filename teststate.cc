#include "teststate.hh"

#include "eventemitter.hh"
#include "eventlistener.hh"
#include "eventtype.hh"

#include "player.hh"

#include <iostream>

namespace jesh {

TestState::TestState(EventEmitter *_emitter, RenderSurface *_surface) :
    GameState(_emitter, _surface),
    player(Point(100, 100)),
    playerView(&player) {
}

void TestState::advance(float difference) {
    this->player.advance(difference);
    this->render();
}

void TestState::render() {
    playerView.renderTo(this->surface);
}

}

