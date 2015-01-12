#include "game.hh"
#include "teststate.hh"
#include "dimensions.hh"

#include <SFML/OpenGL.hpp>
#include <SFML/window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <thread>
#include <vector>

#define GAME_TITLE "Jeshim"
#define GAME_WIDTH 800
#define GAME_HEIGHT 600

int main(void) {
    jesh::Window window(GAME_TITLE, jesh::Dimensions(GAME_WIDTH, GAME_HEIGHT));

    jesh::Game jeshim(window);
    jesh::TestState testState(jeshim, window, window);

    jeshim.setState(&testState);
    jeshim.run();

    return 0;
}
