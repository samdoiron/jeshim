#ifndef JESH_SPRITESURFACE_H_
#define JESH_SPRITESURFACE_H_

#include "rendersurface.hh"
#include "sprite.hh"
#include "dimensions.hh"

namespace jesh {

class SpriteSurface : public RenderSurface {
    public:
        SpriteSurface(Dimensions);
        ~SpriteSurface();
        Sprite &asSprite();

    private:
        Sprite *sprite;
        sf::RenderTexture sfmlTexture;
};

}

#endif // JESH_SPRITESURFACE_H_



