#ifndef JESH_PLAYERVIEW_H_
#define JESH_PLAYERVIEW_H_

#include "view.hh"

#include "sprite.hh"

namespace jesh {

class Player;

class PlayerView : public View {
    public:
        PlayerView(Player&);
        void renderTo(RenderSurface&);
    private:
        int frameNumber;
        Player &player;
        Sprite rightSprite;
        Sprite leftSprite;
        Sprite downSprite;
        Sprite upSprite;
        Sprite *currentSprite;
};

}

#endif // JESH_PLAYERVIEW_H_
