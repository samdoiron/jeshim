#include "entity.hh"

namespace jesh {

Entity::Entity(sf::Drawable &theView, Dimensions theDimensions) :
    Collidable(theDimensions),
    view(theView) {
}

void Entity::draw(sf::RenderTarget &theTarget, sf::RenderStates theStates) const {
    theTarget.draw(view, theStates);
}

void Entity::anchor() {
}

void Entity::advance(double) {
}

Entity::~Entity() {
}

}
