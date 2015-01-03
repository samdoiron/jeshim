
#ifndef JESH_WINDOW_H_
#define JESH_WINDOW_H_

#include "dimensions.hh"
#include "rendersurface.hh"

#include <SFML/Window.hpp>

#include <string>

namespace jesh {

class Window {
    public:
        Window(std::string, Dimensions);
        RenderSurface *getSurface();
        void update();
    private:
        RenderSurface surface;
        sf::RenderWindow sfmlWindow;
        Dimensions dimensions;
        void pollEvents();
};

}


#endif // JESH_WINDOW_H_


