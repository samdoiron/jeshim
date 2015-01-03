
#ifndef JESH_WINDOW_H_
#define JESH_WINDOW_H_

#include "dimensions.hh"
#include "rendersurface.hh"
#include "sprite.hh"

#include <SFML/Window.hpp>

#include <string>

namespace jesh {

class Window : RenderSurface {
    public:
        Window(std::string, Dimensions);

        // via RenderSurface
        void clear();
        void render(Sprite);
        void update();

        bool isOpen();
    private:
        sf::RenderWindow sfmlWindow;
        Dimensions dimensions;
        void pollEvents();
};

}


#endif // JESH_WINDOW_H_


