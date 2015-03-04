#include "entity.hh"
#include "rendersurface.hh"

namespace jesh {

Entity::Entity(View &_view, Dimensions dim) :
    Collidable(dim),
    view(_view) {
}

void Entity::anchor() {
}

void Entity::advance(double) {
    // Do nothing, as child hasn't overridden us.
}

void Entity::renderTo(RenderSurface &surface) {
    view.renderTo(surface);
}

Entity::~Entity() {
}

}
