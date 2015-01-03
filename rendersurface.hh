#ifndef JESH_RENDERSURFACE_H_
#define JESH_RENDERSURFACE_H_

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/window.hpp>

#include "dimensions.hh"
#include "entity.hh"
#include "point.hh"
#include "sprite.hh"

namespace jesh {

/* abstract */ class RenderSurface {
    public:
        virtual void clear() = 0;
        virtual void render(Sprite) = 0;
        virtual void update() = 0;

    private:
        virtual void anchor();
};

}

#endif // JESH_RENDERSURFACE_H_

