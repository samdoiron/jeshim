
#include "entity.hh"

#include "dimensions.hh"
#include "point.hh"

namespace jesh {

Entity::Entity(Dimensions dim, Point pos) {
    this->position = pos;
    this->dimensions = dim;
}

Entity::Entity() {
}

}

