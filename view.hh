#ifndef JESH_VIEW_H_
#define JESH_VIEW_H_

#include "rendersurface.hh"

namespace jesh {

/* abstract */ class View {
    public:
        virtual void renderTo(RenderSurface&) = 0;
        virtual ~View();
    private:
        virtual void anchor();
};

}

#endif // JESH_VIEW_H_

