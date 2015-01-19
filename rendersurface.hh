#ifndef JESH_RENDERSURFACE_H_
#define JESH_RENDERSURFACE_H_

#include "sprite.hh"
#include "point.hh"

namespace jesh {

/* abstract */ class RenderSurface {
    public:
        virtual void clear() = 0;
        virtual void render(Sprite&) = 0;
        virtual void setOrigin(Point) = 0;
        virtual void update() = 0;
        virtual ~RenderSurface() { }

    private:
        virtual void anchor();
};

}

#endif // JESH_RENDERSURFACE_H_

