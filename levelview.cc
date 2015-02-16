#include "levelview.hh"

#include "level.hh"
#include "rendersurface.hh"
#include "tiletype.hh"
#include "dimensions.hh"
#include "point.hh"
#include "sprite.hh"

#include <iostream>

namespace jesh {

// TODO:SPEED This could reasonably use a SFML vertex array, which would
// seriously speed up paints.

LevelView::LevelView(Level &_level) :
    level(_level),
    playerView(level.player) {
    spriteCache.reserve(Tile::kNumTypes);

    Point defaultPosition = Point(0, 0);
    Dimensions tileDimensions = Dimensions(Tile::Size, Tile::Size);

    spriteCache[Tile::kVoid] = new Sprite("void.png", tileDimensions, defaultPosition);
    spriteCache[Tile::kDirt] = new Sprite("dirt.png", tileDimensions, defaultPosition);
    spriteCache[Tile::kWall] = new Sprite("wall.png", tileDimensions, defaultPosition);
}

void LevelView::renderTo(RenderSurface &surface) {
    renderTiles(surface);
    renderPlayer(surface);
}

void LevelView::renderTiles(RenderSurface &surface) {
    std::vector<std::vector<Tile*>> grid = level.tiles;

    // Give all tiles appropriate positions.
    // TODO:SPEED this could easily be done in advance, and cached.
    for (size_t rowNum = 0; rowNum < grid.size(); rowNum++) {
        std::vector<Tile*> row = grid[rowNum];
        for (size_t colNum = 0; colNum < grid[0].size(); colNum++) {
            Tile *tile = row[colNum];
            Sprite *tileSprite = spriteCache[tile->getType()];
            tileSprite->setPosition(
              Point(colNum * Tile::Size, rowNum * Tile::Size)
            );
            surface.render(*tileSprite);
        }
    }
}

void LevelView::renderPlayer(RenderSurface &surface) {
    playerView.renderTo(surface);
}

LevelView::~LevelView() {
    for (Sprite *sprite : spriteCache) {
        delete sprite;
        sprite = nullptr;
    }
}

}
