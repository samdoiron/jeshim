#include "entity.hh"

namespace jesh {

Entity::Entity(Dimensions dim) :
  Collidable(dim) {
}

void Entity::anchor() {
}

Entity::~Entity() {
}

}
