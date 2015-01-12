#include "entity.hh"

#include "dimensions.hh"
#include "point.hh"

namespace jesh {

Entity::Entity(Dimensions dim, Point pos) :
    dimensions(dim),
    position(pos) { 
}

// Maybe don't assume that every Entity has position and size?

Point Entity::getPosition() {
    return this->position;
}

Dimensions Entity::getDimensions() {
    return this->dimensions;
}

Entity::~Entity() {
}

void Entity::anchor() {
}


}

