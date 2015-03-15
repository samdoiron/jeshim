#ifndef LEVEL_VIEW_H_
#define LEVEL_VIEW_H_

#include <sfml/Graphics.hpp>

#include "level.hh"
#include "sprite.hh"
#include "playerview.hh"

#include <memory>

namespace jesh {

class LevelView : public sf::Drawable {
    public:
        LevelView(Level&);
        ~LevelView();

        void draw(sf::RenderTarget&, sf::RenderStates) const;
        void drawRow(sf::RenderTarget&, sf::RenderStates, std::vector<Tile>) const;
        void drawTile(sf::RenderTarget&, sf::RenderStates, Tile) const;
        void drawTiles(sf::RenderTarget&, sf::RenderStates) const;
        void drawEntities(sf::RenderTarget&, sf::RenderStates) const;
    private:
        Level &level;
        mutable std::vector<sf::Sprite> tileSprites;
};

}

#endif // LEVEL_VIEW_H_
