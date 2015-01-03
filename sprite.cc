
#include <string>

#include "dimensions.hh"
#include "point.hh"

#include "sprite.hh"

namespace jesh {

Sprite::Sprite(std::string texturePath, Dimensions dim, Point pos) :
    dimensions(dim),
    position(pos) {

    sf::Texture spriteTexture;
    spriteTexture.loadFromFile(texturePath, dim.asSFMLIntRect(pos));

    this->sfmlSprite = sf::Sprite();
}

sf::Sprite Sprite::asSFMLSprite() {
    return this->sfmlSprite;
}


}

