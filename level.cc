#include "level.hh"

#include "tile.hh"
#include "fixedtile.hh"
#include "slime.hh"
#include "basiccollisionsystem.hh"
#include "debugutils.hh"
#include "dimensions.hh"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace jesh {
// Level is responsible for:
// Loading Level files
// Building a static wall geometry
// Checking for collisions within said geometry
// Storing entity and player position

typedef std::vector<Tile*> Row;
const int kNumSlimes = 1000;

Level::Level(Player &_player, EventEmitter &_events, std::string filePath) :
    player(_player),
    events(_events) {
  loadFromFile(filePath);
  addEnemies();
  setupCollisions();
}

void Level::advance(double secondsPassed) {
  advanceEntities(secondsPassed);
  checkCollisions();
}

Dimensions Level::getDimensions() {
    return Dimensions(tiles[0].size() * Tile::kSize, tiles.size() * Tile::kSize);
}

// private

void Level::addEnemies() {
    for (int i = 0; i < kNumSlimes; i++) {
        Enemy *slime = new Slime();
        slime->setPosition(Point(rand() % static_cast<int>(getDimensions().getWidth()), rand() % static_cast<int>(getDimensions().getHeight())));
        addEnemy(slime);
    }
}

void Level::addEnemy(Enemy* enemy) {
    collisions.addCollidable(enemy);
    enemies.push_back(enemy);
}

void Level::setupCollisions() {
    collisions.setDimensions(getDimensions());
    for (Row eachRow : tiles) {
        for (Tile *eachTile : eachRow) {
            eachTile->addToCollisionSystem(collisions);
        }
    }
    collisions.addCollidable(&player);
}

void Level::advanceEntities(double secondsPassed) {
  player.advance(secondsPassed);
  for (Enemy *enemy : enemies) {
      enemy->advance(secondsPassed);
  }
}

void Level::checkCollisions() {
  collisions.checkCollisions();
}

// CLEAN:BIG
void Level::loadFromFile(std::string filePath) {
  std::ifstream levelFile;
  levelFile.open(filePath);

  int numRows, numCols;
  levelFile >> numRows >> numCols;

  for (int iRow = 0; iRow < numRows; iRow++) {
    std::vector<Tile*> row;
    for (int iCol = 0; iCol < numCols; iCol++) {
      char tileChar;
      levelFile >> tileChar;
      Tile *tile = getTileFromChar(tileChar);
      tile->setPosition(Point(iCol * Tile::kSize, iRow * Tile::kSize));
      row.push_back(tile);
    }
    tiles.push_back(row);
  }

  levelFile.close();
}

// TODO:REFACTOR Possible switch o' death here.
Tile *Level::getTileFromChar(char tileSymbol) {
  switch (tileSymbol)   {
  case '.':
    return new Tile(Tile::kDirt);
  case '#':
    return new FixedTile(Tile::kWall);
  default:
    return new Tile(Tile::kVoid);
  }
}

Level::~Level() {
    for (Row row : tiles) {
        for (Tile *tile : row) {
            delete tile;
        }
    }
    for (Enemy *enemy : enemies) {
        delete enemy;
    }
}

}
