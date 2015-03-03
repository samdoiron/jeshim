#include "singlespriteview.hh"

#include "collidable.hh"
#include "dimensions.hh"

namespace jesh {

SingleSpriteView::SingleSpriteView(Collidable &toTrack, std::string path) :
    tracked(toTrack),
    sprite(path, toTrack.getDimensions(), toTrack.getPosition()) {
}

void SingleSpriteView::renderTo(RenderSurface &surface) {
    sprite.setPosition(tracked.getPosition());
    surface.render(sprite);
}
    
}

