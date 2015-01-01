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
    // TODO
}

}

