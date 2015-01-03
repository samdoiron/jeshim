#ifndef JESH_RENDERSURFACE_H_
#define JESH_RENDERSURFACE_H_

#include "sprite.hh"

namespace jesh {

/* abstract */ class RenderSurface {
    public:
        virtual void clear() = 0;
        virtual void render(Sprite) = 0;
        virtual void update() = 0;
        virtual ~RenderSurface() { }

    private:
        virtual void anchor();
};

}

#endif // JESH_RENDERSURFACE_H_

