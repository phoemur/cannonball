#ifndef HOUSE_H
#define HOUSE_H

#include "texture.h"

#include "SDL.h"

class House {
    Texture t;
    int mPosX, mPosY;
public:
    House();
    void setPos(int x, int y);
    void render();
    SDL_Rect getCollider();
};

#endif // HOUSE_H
