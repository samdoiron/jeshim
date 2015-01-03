
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

    sf::Texture spriteTexture;

    if (!spriteTexture.loadFromFile(texturePath, dim.asSFMLIntRect(pos))) {
        std::ostringstream error;
        error << "Unable to load texture at \"" << texturePath << "\".";
        throw std::runtime_error(error.str());
    }

    this->sfmlSprite.setTexture(spriteTexture);
}

sf::Sprite Sprite::asSFMLSprite() {
    return this->sfmlSprite;
}


}

