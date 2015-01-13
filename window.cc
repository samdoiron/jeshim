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

void Window::render(Sprite &toRender) {
    sfmlWindow.draw(toRender.asSFMLSprite());
}

// TODO: Maybe seperate polling and displaying? Window::update is not very SRP.
void Window::update() {
    pollEvents();
    sfmlWindow.display();
}

bool Window::isOpen() {
    return sfmlWindow.isOpen();
}

void Window::clear() {
    sfmlWindow.clear(sf::Color::Black);
}

// --- private

void Window::pollEvents() {
    sf::Event event;
    while (sfmlWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            sfmlWindow.close();
        } else {
            Event *translated = translateEvent(event);
            if (translated != nullptr) {
                broadcast(*translated);
            }
        }
    }
}

// TODO this should probably be somewhere else.
Event *Window::translateEvent(sf::Event toTranslate) {
    if (toTranslate.type == sf::Event::MouseMoved) {
        return new MouseMoveEvent(
            jesh::Point(toTranslate.mouseMove.x, toTranslate.mouseMove.y)
        );
    } else if (toTranslate.type == sf::Event::KeyPressed) {
    } else {

    }
    return nullptr;
}


}
