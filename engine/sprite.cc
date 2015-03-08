#include "sprite.hh"

#include "util/exceptions.hh"
#include <sfml/Graphics.hpp>

#include <vector>
#include <iostream>

namespace jesh {

const int kSpriteSize = 64;
const int kSpritesheetSize = 256;
const int kSpritesPerRow = 16;
const int kSpritesPerCol = 16;

sf::Image Sprite::spritesheetImage;
sf::Texture Sprite::spritesheet;

/* static */ sf::Sprite Sprite::get(ID theSpriteID) {
    sf::Sprite sprite;
    sprite.setTextureRect(sf::IntRect(
        (theSpriteID % kSpritesPerRow) * kSpriteSize,
        (theSpriteID / kSpritesPerCol) * kSpriteSize,
        kSpriteSize, kSpriteSize
    ));
    sprite.setTexture(spritesheet);
    sprite.setScale(2, 2);
    return sprite;
}

/* static */ void Sprite::initialize() {
    if (!spritesheetImage.loadFromFile("etc/images/sheet.png")) {
        throw_error("Unable to load spritesheet.");
    }

    // Set "Magic Pink" (#ff00ff) as meaning "fully transparent".
    // This is better for efficiency, or something.
    spritesheetImage.createMaskFromColor(sf::Color(255, 0, 255));
    spritesheet.loadFromImage(spritesheetImage);
    spritesheet.setSmooth(false);
}
    
}

