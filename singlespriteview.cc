#include "singlespriteview.hh"

#include "collidable.hh"
#include "dimensions.hh"

namespace jesh {

SingleSpriteView::SingleSpriteView(Collidable &toTrack, std::string path) :
    tracked(toTrack),
    sprite(path, toTrack.getDimensions(), toTrack.getTopLeft()) {
}

void SingleSpriteView::renderTo(RenderSurface &surface) {
    sprite.setPosition(tracked.getTopLeft());
    surface.render(sprite);
}
    
}

