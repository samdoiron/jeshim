#ifndef JESH_PLAYERVIEW_H_
#define JESH_PLAYERVIEW_H_

#include <sfml/Graphics.hpp>
#include <vector>
#include "sprite.hh"

namespace jesh {

class Player;

class PlayerView : public sf::Drawable {
    public:
        PlayerView(Player&);
        void draw(sf::RenderTarget&, sf::RenderStates) const;
    private:
        mutable int framesWithAnimation;
        mutable size_t animationFrame;
        mutable size_t knockbackFrame;
        Player &player;
        mutable sf::Sprite *neutralSprite;
        mutable std::vector<sf::Sprite> runRight;
        mutable std::vector<sf::Sprite> runLeft;
        mutable std::vector<sf::Sprite> runUp;
        mutable std::vector<sf::Sprite> runDown;
        mutable sf::Sprite neutralRight;
        mutable sf::Sprite heart;
};

}

#endif // JESH_PLAYERVIEW_H_
