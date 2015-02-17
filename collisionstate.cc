#include "collisionstate.hh"

namespace jesh {

CollisionState::CollisionState(Game &_game, EventEmitter &_emitter, RenderSurface &_surface) :
    GameState(_game, _emitter, _surface),
    squareOne(_emitter, true),
    squareTwo(_emitter, false),
    viewOne(squareOne),
    viewTwo(squareTwo) {
    collisions.addCollidable(&squareOne);
    collisions.addCollidable(&squareTwo);
    squareTwo.setPosition(Point(200, 200));
}

void CollisionState::advance(double secondsPassed) {
    squareOne.advance(secondsPassed);
    squareTwo.advance(secondsPassed);
    collisions.checkCollisions();
    render();
}

void CollisionState::render() {
    viewOne.renderTo(surface);
    viewTwo.renderTo(surface);
}

}
