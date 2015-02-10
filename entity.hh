
#ifndef JESH_ENTITY_H_
#define JESH_ENTITY_H_

#include "point.hh"
#include "collidable.hh"
#include "dimensions.hh"
#include "rendersurface.hh"

namespace jesh {

class RenderSurface;

// An entity is a body that makes decisions and changes as
// time progresses.
// Maybe rename this into `Advanceable` or `Temporal`

class Entity : public Collidable {
    public:
        Entity(Dimensions);
        virtual ~Entity();
        virtual void advance(double) = 0;

    private:
        virtual void anchor();
};

}

#endif // JESH_ENTITY_H_
