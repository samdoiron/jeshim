#ifndef JESH_SINGLESPRITEVIEW_H_
#define JESH_SINGLESPRITEVIEW_H_

#include "rendersurface.hh"
#include "view.hh"
#include "collidable.hh"

#include <string>

namespace jesh {

class SingleSpriteView : public View {
    public:
        SingleSpriteView(Collidable&, std::string);
        void renderTo(RenderSurface&);
    private:
        Collidable &tracked;
        Sprite sprite;
};

}

#endif // JESH_SINGLESPRITEVIEW_H_


