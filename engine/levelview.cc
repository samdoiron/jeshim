#include "levelview.hh"

#include "geometry/dimensions.hh"
#include "geometry/point.hh"

#include "level.hh"
#include "tiletype.hh"
#include "sprite.hh"

#include <iostream>

namespace jesh {

// TODO:SPEED This could reasonably use a SFML vertex array, which would
// seriously speed up paints.

LevelView::LevelView(Level &_level) :
    level(_level) {
    tileSprites.reserve(Tile::kNumTypes);
    tileSprites[Tile::kDirt] = Sprite::get(Sprite::kCaveFloor);
    tileSprites[Tile::kVoid] = Sprite::get(Sprite::kVoid);
    tileSprites[Tile::kWall] = Sprite::get(Sprite::kWall);
}

void LevelView::draw(sf::RenderTarget &theTarget, sf::RenderStates theStates) const {
    drawTiles(theTarget, theStates);
    drawEnemies(theTarget, theStates);
    theTarget.draw(level.player, theStates);
}


void LevelView::drawTiles(sf::RenderTarget &theTarget, sf::RenderStates theStates) const {
    std::vector<std::vector<Tile*>> grid = level.tiles;

    for (size_t i = 0; i < grid.size(); i++) {
        for (size_t j = 0; j < grid.size(); j++) {
            sf::Sprite tileSprite = tileSprites[grid[i][j]->getType()];
            tileSprite.setPosition(
                i * Tile::kSize,
                j * Tile::kSize
            );
            theTarget.draw(tileSprite, theStates);
        }
    }
    for (std::vector<Tile*> row : grid) {
        for (Tile *tile : row) {
        }
    }
}

// TODO Add EnemyType enum to enemies to be able to display them distinctly.
void LevelView::drawEnemies(sf::RenderTarget &theTarget, sf::RenderStates theStates) const {
    for (Enemy *enemy : level.enemies) {
        theTarget.draw(*enemy, theStates);
    } 
}

LevelView::~LevelView() {
}

}
