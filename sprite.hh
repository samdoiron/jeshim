#ifndef JESH_SPRITE_H_
#define JESH_SPRITE_H_

#include "dimensions.hh"
#include "point.hh"

#include <string>

namespace jesh {

class Sprite {
    public:
        Sprite(std::string path, Dimensions, Point);
        sf::Sprite asSFMLSprite();
    private:
        sf::Sprite sfmlSprite;
        sf::Texture spriteTexture;
        Dimensions dimensions;
        Point position;
};

}

#endif // JESH_SPRITE_H_


