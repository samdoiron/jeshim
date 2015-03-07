#include "rendersurface.hh"
#include <sfml/Graphics.hpp>
#include "exceptions.hh"

namespace jesh {

RenderSurface::RenderSurface(sf::RenderTarget &theTarget) :
    sfmlTarget(theTarget),
    origin(0, 0) {
    if (!arial.loadFromFile("fonts/arial.ttf")) {
        throw_error("Could not find Arial font!");
    }
}

void RenderSurface::update() {
    // This space intentionally left blank.
    // This step is only needed for Window, not SpriteSurface
}

void RenderSurface::clear() {
    sfmlTarget.clear(sf::Color::Black);
}

void RenderSurface::setOrigin(Point newOrigin) {
    origin = newOrigin;
    sf::View windowView = sfmlTarget.getView();
    windowView.setCenter(
        // Add 0.5 before cast to round.
        static_cast<int>(origin.getX() + 0.5),
        static_cast<int>(origin.getY() + 0.5)
    );
    sfmlTarget.setView(windowView);
}

Point RenderSurface::getOrigin() {
    return origin;
}

void RenderSurface::render(Sprite &toRender) {
    sfmlTarget.draw(toRender.asSFMLSprite());
}

void RenderSurface::drawVertices(std::vector<Point> theVerticies) {
    sf::ConvexShape polygon(theVerticies.size());
    for (size_t i = 0; i < theVerticies.size(); i++) {
        polygon.setPoint(i, theVerticies[i].asSFMLVector());
    }
    sfmlTarget.draw(polygon);
}

void RenderSurface::drawLine(Point theStart, Point theEnd) {
    sf::Vertex vertices[] = {
        theStart.asSFMLVector(),
        theEnd.asSFMLVector()
    };
    sfmlTarget.draw(vertices, 2, sf::Lines);
}

void RenderSurface::drawText(Point theTopLeft, std::string theText) {
    sf::Text text;
    text.setPosition(theTopLeft.asSFMLVector());
    text.setFont(arial);
    text.setString(theText);
    text.setCharacterSize(24);
    text.setColor(sf::Color::White);
    sfmlTarget.draw(text);
}

}

