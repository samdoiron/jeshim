#include "fixedtile.hh"
#include "physics/collisionsystem.hh"

namespace jesh {

FixedTile::FixedTile(Tile::Type type) :
  Tile(type) {
  setFixed();
}

void FixedTile::addToCollisionSystem(CollisionSystem &system) {
  system.addCollidable(this);
}

}
