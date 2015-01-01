#ifndef JESH_RENDERSURFACE_H_
#define JESH_RENDERSURFACE_H_

#include <vector>

#include <SFML/OpenGL.hpp>
#include <SFML/window.hpp>
#include <SFML/Graphics.hpp>

#include "entity.hh"

namespace jesh {

class RenderSurface {
    public:
        RenderSurface(int, int);
        void addEntity();
        void tick();
    private:
        sf::RenderWindow window;
        //std::vector<Entity*> entities;
};

}

#endif // JESH_RENDERSURFACE_H_

