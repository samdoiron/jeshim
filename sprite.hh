#ifndef JESH_SPRITE_H_
#define JESH_SPRITE_H_

#include "dimensions.hh"
#include "point.hh"

#include <string>

namespace jesh {

class Sprite {
    public:
        Sprite(std::string path, jesh::Dimensions, jesh::Point);
        sf::Sprite asSFMLSprite();
    private:
        sf::Sprite sfmlSprite;
        Point position;
        Dimensions dimensions;
};

}

#endif // JESH_SPRITE_H_


