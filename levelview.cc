#include "levelview.hh"

#include "level.hh"
#include "rendersurface.hh"
#include "tiletype.hh"
#include "dimensions.hh"
#include "point.hh"
#include "sprite.hh"

namespace jesh {

const int kTileSize = 16;
const int kTileScale = 4;

LevelView::LevelView(Level &_level) :
    level(_level) {
    spriteCache.reserve(kNumTileTypes);

    Point defaultPosition = Point(0, 0);
    Dimensions tileDimensions = Dimensions(kTileSize * kTileScale, kTileSize * kTileScale);

    spriteCache[kDirt] = new Sprite("dirt.png", tileDimensions, defaultPosition);
    spriteCache[kWall] = new Sprite("wall.png", tileDimensions, defaultPosition);
    spriteCache[kVoid] = new Sprite("void.png", tileDimensions, defaultPosition);

    for (Sprite *sprite : spriteCache) {
        sprite->setScale(kTileScale);
    }
}

void LevelView::renderTo(RenderSurface& surface) {
    std::vector<std::vector<Tile>> grid = level.getGrid();

    // Give all tiles appropriate positions.
    // TODO:SPEED this could easily be done in advance, and cached.
    for (size_t rowNum = 0; rowNum < grid.size(); rowNum++) {
        std::vector<Tile> row = grid[rowNum];
        for (size_t colNum = 0; colNum < grid[0].size(); colNum++) {
            Tile tile = row[colNum];
            Sprite *tileSprite = spriteCache[tile];
            tileSprite->setPosition(
                Point(colNum * kTileSize, rowNum * kTileSize)
            );
            surface.render(*tileSprite);
        }
    }
}

LevelView::~LevelView() {
    for (Sprite *sprite : spriteCache) {
        delete sprite;
        sprite = nullptr;
    }
}
    
}

