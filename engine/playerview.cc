#include "playerview.hh"

#include <iostream>

#include "player.hh"

namespace jesh {

const int kFramesPerAnimation = 6;

PlayerView::PlayerView(Player &_player) :
    player(_player),
    heart(Sprite::get(Sprite::kHeart)),
    knockbackFrame(0),
    neutralRight(Sprite::get(Sprite::kPlayerRight)),
    framesWithAnimation(0),
    neutralSprite(&neutralRight),
    animationFrame(0) {
    runRight = {
        Sprite::get(Sprite::kPlayerRunRight1),
        Sprite::get(Sprite::kPlayerRunRight2),
        Sprite::get(Sprite::kPlayerRunRight3),
        Sprite::get(Sprite::kPlayerRight),
        Sprite::get(Sprite::kPlayerRunRight5),
        Sprite::get(Sprite::kPlayerRunRight6),
        Sprite::get(Sprite::kPlayerRunRight3),
        Sprite::get(Sprite::kPlayerRight)
    };
    runLeft = {
        Sprite::get(Sprite::kPlayerRunLeft1),
        Sprite::get(Sprite::kPlayerRunLeft2),
        Sprite::get(Sprite::kPlayerRunLeft3),
        Sprite::get(Sprite::kPlayerLeft),
        Sprite::get(Sprite::kPlayerRunLeft5),
        Sprite::get(Sprite::kPlayerRunLeft6),
        Sprite::get(Sprite::kPlayerRunLeft3),
        Sprite::get(Sprite::kPlayerLeft)
    };
    runUp = {
        Sprite::get(Sprite::kPlayerRunUp1),
        Sprite::get(Sprite::kPlayerRunUp2),
        Sprite::get(Sprite::kPlayerRunUp3),
        Sprite::get(Sprite::kPlayerUp),
        Sprite::get(Sprite::kPlayerRunUp5),
        Sprite::get(Sprite::kPlayerRunUp6),
        Sprite::get(Sprite::kPlayerRunUp3),
        Sprite::get(Sprite::kPlayerUp)
    };
    runDown = {
        Sprite::get(Sprite::kPlayerRunDown1),
        Sprite::get(Sprite::kPlayerRunDown2),
        Sprite::get(Sprite::kPlayerRunDown3),
        Sprite::get(Sprite::kPlayerDown),
        Sprite::get(Sprite::kPlayerRunDown5),
        Sprite::get(Sprite::kPlayerRunDown6),
        Sprite::get(Sprite::kPlayerRunDown3),
        Sprite::get(Sprite::kPlayerDown)
    };
}

void PlayerView::draw(sf::RenderTarget &theTarget, sf::RenderStates theStates) const {
    sf::Sprite currentSprite = *neutralSprite;

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(
        static_cast<float>(player.dimensions.getWidth()),
        static_cast<float>(player.dimensions.getHeight())
    ));
    rect.setPosition(sf::Vector2f(
        static_cast<float>(player.getTopLeft().getX()),
        static_cast<float>(player.getTopLeft().getY())
    ));
    rect.setFillColor(sf::Color::Green);
    theTarget.draw(rect, theStates);

    // Draw hearts
    for (int i = 0; i < player.health; i++) {
        heart.setPosition(theTarget.mapPixelToCoords(sf::Vector2i(10 + (40 * i), 10)));
        theTarget.draw(heart, theStates);
    }

    // Draw sword
    theTarget.draw(player.sword, theStates);

    if (player.velocity.getMagnitude() > 0) {
        framesWithAnimation += 1;
        if (framesWithAnimation == kFramesPerAnimation) {
            animationFrame += 1;
            animationFrame %= 8;
            framesWithAnimation = 0;
        }
        switch (player.facing) {
            case kUp:
                currentSprite = runUp[animationFrame];
                neutralSprite = &runUp[3];
                break;
            case kDown:
                currentSprite = runDown[animationFrame];
                neutralSprite = &runDown[3];
                break;
            case kLeft:
                currentSprite = runLeft[animationFrame];
                neutralSprite = &runLeft[3];
                break;
            case kRight:
                currentSprite = runRight[animationFrame];
                neutralSprite = &runRight[3];
                break;
            default:
                break;
        }
    } else {
        // Keep previous facing.
    }

    if (!player.isKnockedBack || rand() % 3 == 0) {
        Point position = player.getTopLeft();
        currentSprite.setPosition(
            static_cast<float>(position.getX()),
            static_cast<float>(position.getY())
        );
        theTarget.draw(currentSprite, theStates);
    }
}

}

