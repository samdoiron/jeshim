
#ifndef JESH_WINDOW_H_
#define JESH_WINDOW_H_

#include "dimensions.hh"
#include "eventemitter.hh"
#include "rendersurface.hh"
#include "event.hh"
#include "sprite.hh"

#include <SFML/Window.hpp>
#include <SFML/Keyboard.hpp>

#include <string>

namespace jesh {

class Window : public RenderSurface, public EventEmitter {
    public:
        Window(std::string, Dimensions);

        // via RenderSurface
        void clear();
        void render(Sprite&);
        void update();

        bool isOpen();
    private:
        sf::RenderWindow sfmlWindow;
        Dimensions dimensions;
        void pollEvents();
        Event *translateEvent(sf::Event);
};

}


#endif // JESH_WINDOW_H_


