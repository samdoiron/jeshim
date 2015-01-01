#include <SFML/window.hpp>

#include "rendersurface.hh"

namespace jesh {

RenderSurface::RenderSurface(int width, int height) : 
    window(sf::VideoMode(width, height), "Jeshim") 
{
}

void RenderSurface::addEntity() {
}

void RenderSurface::tick() {
    sf::Event event;
    this->window.pollEvent(event);
    if (event.type == sf::Event::Closed) {
        window.close();
    }
}

}

