
#include "sprite.hh"

#include "dimensions.hh"
#include "point.hh"

#include <stdexcept>
#include <string>
#include <sstream>

namespace jesh {

Sprite::Sprite(std::string texturePath, Dimensions dim, Point pos) :
    dimensions(dim),
    position(pos) {

    if (!this->spriteTexture.loadFromFile(texturePath, dim.asSFMLIntRect(Point(0, 0)))) {
        std::ostringstream error;
        error << "Unable to load texture at \"" << texturePath << "\".";
        throw std::runtime_error(error.str());
    }

    this->sfmlSprite.setTexture(spriteTexture);
    this->sfmlSprite.setPosition(pos.getX(), pos.getY());
}

void Sprite::setPosition(Point newPosition) {
    this->position = newPosition;
    this->sfmlSprite.setPosition(newPosition.getX(), newPosition.getY());
}

sf::Sprite Sprite::asSFMLSprite() {
    return this->sfmlSprite;
}

}

