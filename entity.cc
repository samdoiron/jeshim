
#include "entity.hh"

#include "dimensions.hh"
#include "point.hh"

namespace jesh {

Entity::Entity(Dimensions dim, Point pos) :
    position(pos),
    dimensions(dim) { 
}


}

