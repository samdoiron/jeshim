#include "window.hh"

#include <iostream>
#include <vector>
#include <string>

#include <sfml/Window.hpp>
#include <sfml/Graphics.hpp>

#include "point.hh"

// Events
#include "mousemoveevent.hh"
#include "keypressevent.hh"
#include "keyreleaseevent.hh"
#include "keycode.hh"

namespace jesh {

Window::Window(std::string title, Dimensions dim) :
    sfmlWindow(
        sf::VideoMode(
            static_cast<unsigned int>(dim.getWidth()),
            static_cast<unsigned int>(dim.getHeight())
        ),
        title
    ),
    dimensions(dim),
    origin(0, 0)
    {
    sfmlWindow.setVerticalSyncEnabled(true);
}

void Window::render(Sprite &toRender) {
    sfmlWindow.draw(toRender.asSFMLSprite());
}

void Window::drawVertices(std::vector<Point> theVerticies) {
    /* sf::Vertex *sfVerticies = (sf::Vertex*)malloc(sizeof(sf::Vertex) * theVerticies.size()); */
    /* for (size_t i = 0; i < theVerticies.size(); i++) { */
    /*     sfVerticies[i] = theVerticies[i].asSFMLVector(); */
    /* } */
    /* sfmlWindow.draw(sfVerticies, theVerticies.size(), sf::Quads); */
    /* free(sfVerticies); */
    sf::ConvexShape polygon(theVerticies.size());
    for (size_t i = 0; i < theVerticies.size(); i++) {
        polygon.setPoint(i, theVerticies[i].asSFMLVector());
    }
    sfmlWindow.draw(polygon);
}

void Window::drawLine(Point theStart, Point theEnd) {
    sf::Vertex vertices[] = {
        theStart.asSFMLVector(),
        theEnd.asSFMLVector()
    };
    sfmlWindow.draw(vertices, 2, sf::Lines);
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

void Window::setOrigin(Point newOrigin) {
    origin = newOrigin;
    sf::View windowView = sfmlWindow.getView();
    windowView.setCenter(
        // Add 0.5 before cast to round.
        static_cast<int>(origin.getX() + 0.5),
        static_cast<int>(origin.getY() + 0.5)
    );
    sfmlWindow.setView(windowView);
}

Point Window::getOrigin() {
    return origin;
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
                broadcast(translated);
            }
            delete translated;
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
        // Safe because jesh keyCodes are the same as SFML keyCodes.
        return new KeyPressEvent(static_cast<KeyCode>(toTranslate.key.code));
    } else if (toTranslate.type == sf::Event::KeyReleased) {
        // Safe because jesh keyCodes are the same as SFML keyCodes.
        return new KeyReleaseEvent(static_cast<KeyCode>(toTranslate.key.code));
    }
    return nullptr;
}


}
