
#ifndef JESH_ENTITY_H_
#define JESH_ENTITY_H_


#include "physics/collidable.hh"
#include "geometry/point.hh"
#include "geometry/dimensions.hh"

#include <sfml/Graphics.hpp>

namespace jesh {

// An entity is a body that makes decisions and changes as
// time progresses.
// Maybe rename this into `Advanceable` or `Temporal`

class Entity : public Collidable, public sf::Drawable {
    public:
        Entity(sf::Drawable&, Dimensions);
        virtual ~Entity();
        virtual void advance(double);
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

    private:
        virtual void anchor();
        sf::Drawable &view;
};

}

#endif // JESH_ENTITY_H_
