#ifndef JESH_TESTQUAREVIEW_H_
#define JESH_TESTQUAREVIEW_H_

#include "view.hh"
#include "testsquare.hh"

namespace jesh {

class TestSquareView : public View {
public:
    TestSquareView(TestSquare&);
    void renderTo(RenderSurface&);
    ~TestSquareView();
private:
    TestSquare &square;
    Sprite *normalSprite;
    Sprite *hitSprite;
};

}

#endif // JESH_TESTQUAREVIEW_H_
