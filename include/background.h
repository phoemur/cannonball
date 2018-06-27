#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "texture.h"

#include <string>

class Background {
    Texture t;
    int scrollingOffset;
public:
    Background(const std::string& path);

    void render();
    void scroll();
};

#endif // BACKGROUND_H
