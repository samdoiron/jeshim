#include <iostream>

#include <SFML/window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#define WORLD_HEIGHT 600
#define WORLD_WIDTH 800

int main(void) {
    sf::RenderWindow window(sf::VideoMode(WORLD_WIDTH, WORLD_HEIGHT), "My Window");
    window.setVerticalSyncEnabled(true);
    sf::Texture player;

    if (!player.loadFromFile("guy.png", sf::IntRect(10, 10, 32, 64))) {
        return -1;
    }

    sf::Sprite sprite;
    sprite.setTexture(player);
    sprite.setScale(sf::Vector2f(2.0f, 2.0f));
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display();
    }
    return 0;
}

