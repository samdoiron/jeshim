#ifndef JESH_SPRITE_H_
#define JESH_SPRITE_H_

#include <sfml/Graphics.hpp>

namespace jesh {

class Sprite {
    // These are based on their locations in etc/images/spritesheet.png
    public:
        enum ID {
            kCaveFloor,
            kPlayer,
            kVoid,
            kWall,
            kNumSprites
        };

        static sf::Sprite get(ID);
        static void initialize();

    private:
        static sf::Image spritesheetImage;
        static sf::Texture spritesheet;
};

}

#endif // JESH_SPRITE_H_


