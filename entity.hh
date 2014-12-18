
#ifndef JESH_ENTITY_H_
#define JESH_ENTITY_H_

namespace jesh {

class Entity {
    public:
        Entity(Dimensions, Point);
        Entity(Point, Dimensions);
    private:
        Dimensions dimensions;
        Point position;
}

}

#endif // JESH_ENTITY_H_

