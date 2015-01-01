
#ifndef JESH_ENTITY_H_
#define JESH_ENTITY_H_

#include "point.hh"
#include "dimensions.hh"
#include "rendersurface.hh"

namespace jesh {

class RenderSurface;

class Entity {
    public:
        Entity(Dimensions, Point);
        Entity(Point, Dimensions);
    private:
        Dimensions dimensions;
        Point position;
        void render(RenderSurface);
};

}

#endif // JESH_ENTITY_H_

