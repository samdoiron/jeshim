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

    if (player.velocity.getMagnitude() > 0) {
        framesWithAnimation += 1;
        if (framesWithAnimation == kFramesPerAnimation) {
            animationFrame += 1;
            animationFrame %= 8;
            framesWithAnimation = 0;
        }
        if (player.velocity.getY() > 0) {
            currentSprite = runDown[animationFrame];
            neutralSprite = &runDown[3];
        } else if (player.velocity.getY() < 0) {
            currentSprite = runUp[animationFrame];
            neutralSprite = &runUp[3];
        } else if (player.velocity.getX() < 0) {
            currentSprite = runRight[animationFrame];
            neutralSprite = &runRight[3];
        } else {
            currentSprite = runLeft[animationFrame];
            neutralSprite = &runLeft[3];
        }
    } else {
    }

    if (!player.isKnockedBack || rand() % 3 == 0) {
        Point position = player.getTopLeft();
        currentSprite.setPosition(position.getX(), position.getY());
        theTarget.draw(currentSprite, theStates);
    }

    // Draw hearts
    for (int i = 0; i < player.health; i++) {
        heart.setPosition(theTarget.mapPixelToCoords(sf::Vector2i(10 + (40 * i), 10)));
        theTarget.draw(heart, theStates);
    }

}

}

