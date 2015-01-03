#include "entity.hh"

#include "dimensions.hh"
#include "point.hh"

namespace jesh {

Entity::Entity(Dimensions dim, Point pos) :
    dimensions(dim),
    position(pos) { 
}


}

