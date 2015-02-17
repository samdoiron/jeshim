#include "tile.hh"
#include "collisionsystem.hh"

#include <memory>

namespace jesh {

Tile::Tile(Tile::Type _type) :
  Collidable(Dimensions(Tile::kSize, Tile::kSize)),
  type(_type) {
}

Tile::Type Tile::getType() {
  return type;
}

void Tile::addToCollisionSystem(CollisionSystem&) {
  // By default, tiles are not collidable.
  // This if overridden by FixedTile.
}

void Tile::handleCollision(Collidable&) {
  // Tiles don't care about collisions.
}

// Enable collision visitor pattern.
void Tile::sendCollision(Collidable &other) {
  other.handleCollision(*this);
}

}
