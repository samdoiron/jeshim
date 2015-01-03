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

class RenderSurface {
    public:
        RenderSurface(Dimensions);
        sf::Texture asSFMLTexture();
        void render(Sprite);

    private:
        sf::RenderTexture texture;
};

}

#endif // JESH_RENDERSURFACE_H_

