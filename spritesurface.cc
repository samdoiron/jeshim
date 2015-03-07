#include <sfml/Graphics.hpp>
#include "spritesurface.hh"
#include "sprite.hh"
#include "dimensions.hh"
#include "exceptions.hh"

namespace jesh {

SpriteSurface::SpriteSurface(Dimensions theDimensions) :
    RenderSurface(sfmlTexture),
    sfmlTexture(),
    sprite(nullptr) {

    int width = static_cast<int>(theDimensions.getWidth());
    int height = static_cast<int>(theDimensions.getHeight());
    if (!sfmlTexture.create(width, height)) {
        throw_error("Could not create render texture.");
    }

    sprite = new Sprite(sfmlTexture.getTexture());
}

Sprite &SpriteSurface::asSprite() {
    sprite->setTexture(sfmlTexture.getTexture());
    sfmlTexture.display();
    return *sprite;
}

SpriteSurface::~SpriteSurface() {
    delete sprite;
}
    
}

