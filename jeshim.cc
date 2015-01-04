#include <SFML/OpenGL.hpp>
#include <SFML/window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <thread>
#include <vector>

#include "game.hh"
#include "teststate.hh"

int main(void) {
    jesh::TestState test;
    jesh::Game jeshim(&test);
    jeshim.run();
}
