#include "game.hh"
#include "engine/levelstate.hh"
#include "geometry/dimensions.hh"
#include "engine/sprite.hh"

#include <SFML/window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <thread>
#include <vector>

#define GAME_TITLE "Jeshim"
#define GAME_WIDTH 800
#define GAME_HEIGHT 600

int main(void) {
    jesh::Sprite::initialize();
    sf::RenderWindow window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), GAME_TITLE, sf::Style::Fullscreen);

    jesh::Game jeshim(window);
    jesh::LevelState levelState(jeshim, window);

    jeshim.setState(&levelState);
    jeshim.run();

    return 0;
}
