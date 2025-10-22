#ifndef APP_TEXPACK_H
#define APP_TEXPACK_H

#include <ngph/texture.h>

namespace cpm {
    class TexPack {
    public:
        gph::Texture exitLabel;
        gph::Texture botMenu;
        gph::Texture background;

        TexPack();
    };
}

#endif