#include "spritesurface.hh"

#include "point.hh"
#include "dimensions.hh"

#include <sfml/Graphics.hpp>

namespace jesh {

SpriteSurface::SpriteSurface(Dimensions theDimensions) :
    sprite(nullptr) {
    sfmlTexture.create(theDimensions.getWidth(), theDimensions.getHeight());
    sprite = new Sprite(sfmlTexture.getTexture());
}

Sprite *SpriteSurface::getSprite() {
    sprite->setTexture(sfmlTexture.getTexture());
    return sprite;
}

void SpriteSurface::setOrigin(Point newOrigin) {
}

Point SpriteSurface::getOrigin() {
    return Point(0, 0);
}

void SpriteSurface::clear() {
    sfmlTexture.clear(sf::Color::Black);
}

void SpriteSurface::render(Sprite &theSprite) {
    sfmlTexture.draw(theSprite.asSFMLSprite());
}

void SpriteSurface::update() {
}

void SpriteSurface::drawLine(Point, Point) {
}

SpriteSurface::~SpriteSurface() {
    delete sprite;
}

}
