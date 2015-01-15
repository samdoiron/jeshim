
#ifndef JESH_ENTITY_H_
#define JESH_ENTITY_H_

#include "point.hh"
#include "dimensions.hh"
#include "rendersurface.hh"

namespace jesh {

class RenderSurface;

/* abstract */ class Entity {
    public:
        Entity(Dimensions, Point);
        Entity(Point, Dimensions);
        Dimensions getDimensions();
        Point getPosition();
        virtual ~Entity();
        virtual void advance(double) = 0;

    protected:
        Dimensions dimensions;
        Point position;

    private:
        virtual void anchor();
};

}

#endif // JESH_ENTITY_H_

