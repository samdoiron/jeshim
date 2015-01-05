#include "window.hh"

#include <iostream>
#include <string>

#include <sfml/Window.hpp>

#include "point.hh"

// Events
#include "mousemoveevent.hh"

namespace jesh {

Window::Window(std::string title, Dimensions dim) :
    sfmlWindow(
        sf::VideoMode(
            static_cast<unsigned int>(dim.getWidth()), 
            static_cast<unsigned int>(dim.getHeight())
        ),
        title
    ),
    dimensions(dim)
    {
}

void Window::render(Sprite toRender) {
    this->sfmlWindow.draw(toRender.asSFMLSprite());
}

// TODO: Maybe seperate polling and displaying? Window::update is not very SRP.
void Window::update() {
    this->pollEvents();
    this->sfmlWindow.display();
}

bool Window::isOpen() {
    return this->sfmlWindow.isOpen();
}

void Window::clear() {
    this->sfmlWindow.clear(sf::Color(rand() % 64, rand() % 64, rand() % 64));
}

// --- private

void Window::pollEvents() {
    sf::Event event;
    while (this->sfmlWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->sfmlWindow.close();
        } else {
            Event *translated = this->translateEvent(event);
            if (translated != NULL) {
                this->broadcast(translated);
            }
        }
    }
}

Event *Window::translateEvent(sf::Event toTranslate) {
    if (toTranslate.type == sf::Event::MouseMoved) {
        return new MouseMoveEvent(
            jesh::Point(toTranslate.mouseMove.x, toTranslate.mouseMove.y)
        );
    }
    return NULL;
}


}
