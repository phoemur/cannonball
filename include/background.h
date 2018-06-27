#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "texture.h"

class Background {
    Texture t;
    int scrollingOffset;
public:
    Background();

    void render();
    void scroll();
};

#endif // BACKGROUND_H
