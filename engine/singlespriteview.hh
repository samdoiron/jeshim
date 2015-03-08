#ifndef JESH_SINGLESPRITEVIEW_H_
#define JESH_SINGLESPRITEVIEW_H_

#include <sfml/Graphics.hpp>
#include "entity.hh"

namespace jesh {

class SingleSpriteView : public sf::Drawable {
    public:
        SingleSpriteView(Entity&, sf::Sprite);
        void draw(sf::RenderTarget&, sf::RenderStates) const;
    private:
        mutable sf::Sprite sprite;
        Entity &entity;
};

}

#endif // JESH_SINGLESPRITEVIEW_H_


