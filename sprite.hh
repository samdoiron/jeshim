#ifndef JESH_SPRITE_H_
#define JESH_SPRITE_H_

#include "dimensions.hh"
#include "point.hh"

#include <string>

namespace jesh {

class Sprite {
    public:
        Sprite();
        Sprite(sf::Texture texture); // Useful for SpriteSurface
        Sprite(std::string path, Dimensions, Point);
        void setPosition(Point);
        sf::Sprite asSFMLSprite();
        void setScale(double);
        void setTexture(sf::Texture);
    private:
        sf::Sprite sfmlSprite;
        sf::Texture spriteTexture;
        Dimensions dimensions;
        Point position;
        void updateSFMLSprite();
};

}

#endif // JESH_SPRITE_H_


