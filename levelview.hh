#ifndef LEVEL_VIEW_H_
#define LEVEL_VIEW_H_

#include "level.hh"
#include "view.hh"
#include "rendersurface.hh"
#include "sprite.hh"
#include "playerview.hh"

#include <memory>

namespace jesh {

class LevelView : public View {
    public:
        LevelView(Level&);

        // via View
        void renderTo(RenderSurface&);
        void renderRow(RenderSurface&, std::vector<Tile>);
        void renderTile(RenderSurface&, Tile);
        void renderTiles(RenderSurface&);
        void renderPlayer(RenderSurface&);

        ~LevelView();
    private:
        Level &level;
        PlayerView playerView;
        // TODO:CLEAN Using pointers here. Wish I didn't.
        std::vector<Sprite*> spriteCache;
};

}

#endif // LEVEL_VIEW_H_
