
#ifndef JESH_ENTITY_H_
#define JESH_ENTITY_H_

#include "collidable.hh"
#include "point.hh"
#include "dimensions.hh"
#include "rendersurface.hh"
#include "view.hh"

namespace jesh {

class RenderSurface;

// An entity is a body that makes decisions and changes as
// time progresses.
// Maybe rename this into `Advanceable` or `Temporal`

class Entity : public Collidable {
    public:
        Entity(View&, Dimensions);
        virtual ~Entity();
        virtual void advance(double);
        virtual void renderTo(RenderSurface&);

    private:
        virtual void anchor();
        View &view;
};

}

#endif // JESH_ENTITY_H_
