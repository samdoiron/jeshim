#include "swordview.hh"
#include "sword.hh"
#include "sprite.hh"
#include "geometry/point.hh"
#include <sfml/Graphics.hpp>

namespace jesh {

SwordView::SwordView(Sword &theSword) :
    sword(theSword) {
}

void SwordView::draw(sf::RenderTarget &theTarget, sf::RenderStates theStates) const {
    if (!sword.isSwinging) {
        return;
    }

    Point position = sword.getPosition();
    Dimensions size = sword.getDimensions();

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(
        static_cast<float>(size.getWidth()),
        static_cast<float>(size.getHeight())
    ));
    rect.setPosition(
        static_cast<float>(position.getX()),
        static_cast<float>(position.getY())
    );
    rect.setFillColor(sf::Color::White);
    theTarget.draw(rect, theStates);
}
    
}

