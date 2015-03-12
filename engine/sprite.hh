#ifndef JESH_SPRITE_H_
#define JESH_SPRITE_H_

#include <sfml/Graphics.hpp>

namespace jesh {

class Sprite {
    // These are based on their locations in etc/images/spritesheet.png
    public:
        enum ID {
            kCaveFloor,
            kWall,
            kWallSide,
            kWallBottom,
            kVoid,
            kSlime,
            kPlayerRunRight1,
            kPlayerRunRight2,
            kPlayerRunRight3,
            kPlayerRight,
            kPlayerRunRight5,
            kPlayerRunRight6,
            kPlayerRunLeft1,
            kPlayerRunLeft2,
            kPlayerRunLeft3,
            kPlayerLeft,
            kPlayerRunLeft5,
            kPlayerRunLeft6,
            kPlayerRunUp1,
            kPlayerRunUp2,
            kPlayerRunUp3,
            kPlayerUp,
            kPlayerRunUp5,
            kPlayerRunUp6,
            kPlayerRunDown1,
            kPlayerRunDown2,
            kPlayerRunDown3,
            kPlayerDown,
            kPlayerRunDown5,
            kPlayerRunDown6,
            kHeart,
            kSword,
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


