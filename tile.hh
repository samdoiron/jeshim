#ifndef JESH_TILE_H_
#define JESH_TILE_H_

#include "collidable.hh"
#include "collisionsystem.hh"

namespace jesh {

class Tile : public Collidable {
public:
  static const int kSize = 64;

  enum Type {
    kVoid,
    kWall,
    kDirt,
    kNumTypes
  };

  Tile(Tile::Type);
  Tile::Type getType();
  virtual void addToCollisionSystem(CollisionSystem&);
  virtual void handleCollision(Collidable&);
  virtual void sendCollision(Collidable&);

private:
  Tile::Type type;
};

}

#endif // JESH_TILE_H_
