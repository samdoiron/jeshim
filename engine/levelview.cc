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
    drawEntities(theTarget, theStates);
    drawPlayer(theTarget, theStates);
}


void LevelView::drawTiles(sf::RenderTarget &theTarget, sf::RenderStates theStates) const {
    for (size_t iRow = 0; iRow < level.tiles.size(); iRow++) {
        std::vector<Tile*> row = level.tiles[iRow];
        for (size_t iCol = 0; iCol < row.size(); iCol++) {
            Tile *eachTile = row[iCol];
            sf::Sprite tileSprite;
            if (eachTile->getType() == Tile::kWall) {
                bool isWallBefore = iCol < row.size() - 1 && row[iCol + 1]->getType() == Tile::kWall;
                bool isWallAfter = iCol > 0 && row[iCol - 1]->getType() == Tile::kWall;
                bool isHorizontal = isWallBefore || isWallAfter;
                if (isHorizontal) {
                    tileSprite = Sprite::get(Sprite::kWall);
                } else {
                    tileSprite = Sprite::get(Sprite::kWallSide);
                }
            } else {
                tileSprite = tileSprites[eachTile->getType()];
            }
            tileSprite.setPosition(eachTile->getPosition().asSFMLVector());
            theTarget.draw(tileSprite, theStates);
        }
    }
}

// TODO Add EnemyType enum to enemies to be able to display them distinctly.
void LevelView::drawEntities(sf::RenderTarget &theTarget, sf::RenderStates theStates) const {
    for (Entity *eachEntity : level.entities) {
        theTarget.draw(*eachEntity, theStates);
    } 
}

void LevelView::drawPlayer(sf::RenderTarget &theTarget, sf::RenderStates theStates) const {
    theTarget.draw(level.player, theStates);
}

LevelView::~LevelView() {
}

}
