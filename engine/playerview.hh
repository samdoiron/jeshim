#ifndef JESH_PLAYERVIEW_H_
#define JESH_PLAYERVIEW_H_

#include <sfml/Graphics.hpp>
#include "sprite.hh"

namespace jesh {

class Player;

class PlayerView : public sf::Drawable {
    public:
        PlayerView(Player&);
        void update();
        void draw(sf::RenderTarget&, sf::RenderStates) const;
    private:
        Player &player;
        mutable sf::Sprite sprite;
};

}

#endif // JESH_PLAYERVIEW_H_
