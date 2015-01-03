
#include "window.hh"

#include <iostream>
#include <string>

namespace jesh {

Window::Window(std::string title, Dimensions dim) :
    sfmlWindow(sf::VideoMode(dim.getWidth(), dim.getHeight()), title),
    dimensions(dim), 
    surface(dim)
    {
}

// TODO this should be somewhere else.
// Temporary to prevent freezing.
//---------------------------------------------------
void Window::update() {
    this->pollEvents();

    this->sfmlWindow.clear(sf::Color::Black);

    sf::Sprite screenSprite;
    screenSprite.setTexture(this->surface.asSFMLTexture());

    this->sfmlWindow.draw(screenSprite);
    this->sfmlWindow.display();
}

RenderSurface *Window::getSurface() {
    return &this->surface;
}

// --- private

void Window::pollEvents() {
    sf::Event event;
    this->sfmlWindow.pollEvent(event);
    if (event.type == sf::Event::Closed) {
        this->sfmlWindow.close();
    }
}

}

