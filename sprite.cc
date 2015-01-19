
#include "sprite.hh"

#include "dimensions.hh"
#include "point.hh"

#include <stdexcept>
#include <string>
#include <sstream>
#include <iostream>

namespace jesh {

Sprite::Sprite(std::string texturePath, Dimensions dim, Point pos) :
    dimensions(dim),
    position(pos) {

    if (!spriteTexture.loadFromFile(texturePath, dim.asSFMLIntRect(Point(0, 0)))) {
        std::ostringstream error;
        error << "Unable to load texture at \"" << texturePath << "\".";
        throw std::runtime_error(error.str());
    }

    sfmlSprite.setTexture(spriteTexture);
    updateSFMLSprite();
}

void Sprite::setPosition(Point newPosition) {
    position = newPosition;
    updateSFMLSprite();
}

void Sprite::setScale(double scale) {
    sfmlSprite.setScale(sf::Vector2f(scale, scale));
}

sf::Sprite Sprite::asSFMLSprite() {
    return sfmlSprite;
}

Sprite::~Sprite() {
    std::cout << "WARNING: DESTROYING SPRITE" << std::endl;
}

// --- private

void Sprite::updateSFMLSprite() {
    sfmlSprite.setPosition(
        static_cast<float>(position.getX()), 
        static_cast<float>(position.getY())
    );
}

}

