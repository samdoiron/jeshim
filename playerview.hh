#ifndef JESH_PLAYERVIEW_H_
#define JESH_PLAYERVIEW_H_

#include "view.hh"

#include "player.hh"
#include "sprite.hh"

namespace jesh {

class PlayerView : public View {
    public:
        PlayerView(Player*);
        void renderTo(RenderSurface*);
    private:
        Player *player;
        Sprite playerSprite;
};

}

#endif // JESH_PLAYERVIEW_H_
