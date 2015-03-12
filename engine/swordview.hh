#ifndef JESH_SWORDVIEW_H_
#define JESH_SWORDVIEW_H_

#include <sfml/Graphics.hpp>

namespace jesh {

class Sword;

class SwordView : public sf::Drawable {
    public:
        SwordView(Sword&);
        void draw(sf::RenderTarget&, sf::RenderStates) const;

    private:
        Sword &sword;
        mutable sf::Sprite swordSprite;
};

}

#endif // JESH_SWORDVIEW_H_


