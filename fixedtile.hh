#ifndef JESH_FIXEDTILE_H_
#define JESH_FIXEDTILE_H_

#include "tile.hh"
#include "collisionsystem.hh"

namespace jesh {

class FixedTile : public Tile {
public:
  FixedTile(Tile::Type);
  virtual void addToCollisionSystem(CollisionSystem&);
};

}


#endif // JESH_FIXEDTILE_H_
