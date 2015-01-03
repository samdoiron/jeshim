
#include "window.hh"

#include <iostream>
#include <string>

namespace jesh {

Window::Window(std::string title, Dimensions dim) :
    sfmlWindow(sf::VideoMode(dim.getWidth(), dim.getHeight()), title),
    dimensions(dim)
    {
    this->sfmlWindow.setVerticalSyncEnabled(true);
}

void Window::render(Sprite toRender) {
    this->sfmlWindow.draw(toRender.asSFMLSprite());
}

// TODO this should be somewhere else.
// Temporary to prevent freezing.
//---------------------------------------------------
void Window::update() {
    this->pollEvents();
    this->sfmlWindow.display();
}

bool Window::isOpen() {
    return this->sfmlWindow.isOpen();
}

void Window::clear() {
    this->sfmlWindow.clear(sf::Color(sf::Color(rand() % 64, rand() % 64, rand() % 64)));
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

