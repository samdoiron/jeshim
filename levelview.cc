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
    level(_level) {
    spriteCache.reserve(Tile::kNumTypes);

    Point defaultPosition = Point(0, 0);
    Dimensions tileDimensions = Dimensions(Tile::kSize, Tile::kSize);

    spriteCache[Tile::kVoid] = new Sprite("void.png", tileDimensions, defaultPosition);
    spriteCache[Tile::kDirt] = new Sprite("dirt.png", tileDimensions, defaultPosition);
    spriteCache[Tile::kWall] = new Sprite("wall.png", tileDimensions, defaultPosition);
}

void LevelView::renderTo(RenderSurface &surface) {
    renderTiles(surface);
    renderEnemies(surface);
    renderPlayer(surface);
}

void LevelView::renderTiles(RenderSurface &surface) {
    std::vector<std::vector<Tile*>> grid = level.tiles;

    // Give all tiles appropriate positions.
    // TODO:SPEED this could easily be done in advance, and cached.
    for (std::vector<Tile*> row : grid) {
        for (Tile *tile : row) {
            Sprite *tileSprite = spriteCache[tile->getType()];
            tileSprite->setPosition(tile->getTopLeft());
            surface.render(*tileSprite);
        }
    }
}

// TODO Add EnemyType enum to enemies to be able to display them distinctly.
void LevelView::renderEnemies(RenderSurface &surface) {
    for (Enemy *enemy : level.enemies) {
        enemy->renderTo(surface);
    } 
}

void LevelView::renderPlayer(RenderSurface &surface) {
    level.player.renderTo(surface);
}

LevelView::~LevelView() {
    for (Sprite *sprite : spriteCache) {
        delete sprite;
        sprite = nullptr;
    }
}

}
