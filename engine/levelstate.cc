#include "levelstate.hh"

#include "geometry/point.hh"
#include "player.hh"

#include <iostream>
#include <memory>

namespace jesh {

LevelState::LevelState(Game &_game, sf::RenderTarget &theTarget) :
    GameState(_game, theTarget),
    target(theTarget),
    currentLevel(player, "etc/levels/test.jesh"),
    levelView(currentLevel) {
    updateCamera();
}

void LevelState::advance(double secondsPassed) {
    currentLevel.advance(secondsPassed);
    updateCamera();
    render();
}

// === private

void LevelState::updateCamera() {
    sf::View view = target.getView();
    Point playerMiddle = player.getMiddle();
    view.setCenter(
        static_cast<float>(playerMiddle.getX()),
        static_cast<float>(playerMiddle.getY())
    );
    target.setView(view);
}

void LevelState::render() {
    target.draw(levelView);
}

}
