#include "testsquareview.hh"
#include "sprite.hh"
#include "dimensions.hh"

namespace jesh {

TestSquareView::TestSquareView(TestSquare &_square) :
    square(_square),
    normalSprite(new Sprite("void.png", Dimensions(250, 250), Point(0, 0))),
    hitSprite(new Sprite("wall.png", Dimensions(250, 250), Point(0, 0))) {
}

void TestSquareView::renderTo(RenderSurface &surface) {
    if (square.isHit) {
        hitSprite->setPosition(square.position);
        surface.render(*hitSprite);
    } else {
        normalSprite->setPosition(square.position);
        surface.render(*normalSprite);
    }
}

TestSquareView::~TestSquareView() {
    delete normalSprite;
    normalSprite = nullptr;
    delete hitSprite;
    hitSprite = nullptr;
}

}
