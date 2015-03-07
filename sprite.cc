
#include "sprite.hh"

#include "exceptions.hh"
#include "dimensions.hh"
#include "point.hh"

#include <string>
#include <sstream>
#include <iostream>

namespace jesh {

Sprite::Sprite(sf::Texture theTexture) :
    dimensions(
        theTexture.getSize().x,
        theTexture.getSize().y
    ),
    position(0, 0) {
    sfmlSprite.setTexture(theTexture);
    updateSFMLSprite();
}

Sprite::Sprite(std::string texturePath, Dimensions dim, Point pos) :
    dimensions(dim),
    position(pos) {

    if (!spriteTexture.loadFromFile(texturePath, Dimensions(0, 0).asSFMLIntRect(Point(0, 0)))) {
        std::ostringstream error;
        error << "Unable to load texture at \"" << texturePath << "\".";
        throw_error(error.str());
    }

    sfmlSprite.setTexture(spriteTexture);
    updateSFMLSprite();
    setScale(2);
}

// Useful for SpriteSurface.
void Sprite::setTexture(sf::Texture theTexture) {
    sfmlSprite.setTexture(theTexture);
}

void Sprite::setPosition(Point newPosition) {
    position = newPosition;
    updateSFMLSprite();
}

void Sprite::setScale(double scale) {
    sfmlSprite.setScale(sf::Vector2f(
        static_cast<float>(scale),
        static_cast<float>(scale)
    ));
}

sf::Sprite Sprite::asSFMLSprite() {
    return sfmlSprite;
}

// --- private

void Sprite::updateSFMLSprite() {
    sfmlSprite.setPosition(
        static_cast<float>(position.getX()), 
        static_cast<float>(position.getY())
    );
}

}

