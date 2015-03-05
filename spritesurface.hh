#ifndef JESH_SPRITESURFACE_H_
#define JESH_SPRITESURFACE_H_

#include "rendersurface.hh"
#include "point.hh"
#include "sprite.hh"
#include "dimensions.hh"

#include <sfml/Graphics.hpp>

namespace jesh {

class SpriteSurface : public RenderSurface {
    public:
        SpriteSurface(Dimensions);
        Point getOrigin();
        Sprite *getSprite();
        void clear();
        void render(Sprite&);
        void setOrigin(Point);
        void update();
        void drawLine(Point, Point);

    private:
        sf::RenderTexture sfmlTexture;
        Sprite *sprite;
        ~SpriteSurface();
};

}

#endif // JESH_SPRITESURFACE_H_


