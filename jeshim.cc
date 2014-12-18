#include <iostream>

#include <SFML/window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <Box2D/Box2D.h>

#define WORLD_HEIGHT 600
#define WORLD_WIDTH 800

int main(void) {
    sf::RenderWindow window(sf::VideoMode(WORLD_WIDTH, WORLD_HEIGHT), "My Window");
    window.setVerticalSyncEnabled(true);
    sf::Texture player;

    b2Vec2 gravity(0.0f, 2.6f);
    b2World world(gravity);

    // Create the ground
    b2BodyDef groundDef;
    b2Body *groundBody = world.CreateBody(&groundDef);
    groundDef.position.Set(0.0f, -8.0f);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(2.0f, 2.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);

    // Create the player
    b2BodyDef playerBodyDef;
    playerBodyDef.type = b2_dynamicBody;
    playerBodyDef.position.Set(5, 0);
    b2Body *playerBody = world.CreateBody(&playerBodyDef);

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

        world.Step(1.0f / 60.0f, 2, 2);
        b2Vec2 position = playerBody->GetPosition();
        sprite.setPosition(sf::Vector2f(position.x * 100, position.y * 100));

        std::cout << "x: " << position.x << " y: " << position.y << std::endl;

        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display();
    }
    return 0;
}

