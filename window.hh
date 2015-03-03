#ifndef JESH_WINDOW_H_
#define JESH_WINDOW_H_

#include "dimensions.hh"
#include "eventemitter.hh"
#include "rendersurface.hh"
#include "event.hh"
#include "sprite.hh"
#include "point.hh"

#include <SFML/Window.hpp>

#include <string>

namespace jesh {

class Window : public RenderSurface, public EventEmitter {
    public:
        Window(std::string, Dimensions);

        // via RenderSurface
        void clear();
        void render(Sprite&);
        void drawLine(Point, Point) override;
        void setOrigin(Point);
        Point getOrigin();
        void update();

        bool isOpen();
    private:
        sf::RenderWindow sfmlWindow;
        Dimensions dimensions;
        Point origin;
        void pollEvents();
        Event *translateEvent(sf::Event);
};

}


#endif // JESH_WINDOW_H_


