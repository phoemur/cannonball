#include "house.h"

House::House()
    : t{}, mPosX{0}, mPosY{0}
{
    t.loadFromFile("./cannonball_assets/house.png");
}

void House::setPos(int x, int y)
{
    mPosX = x;
    mPosY = y;
}

void House::render()
{
    t.render(mPosX, mPosY);
}

SDL_Rect House::getCollider()
{
    SDL_Rect res;
    res.x = mPosX;
    res.y = mPosY;
    res.w = t.getWidth();
    res.h = t.getHeight();

    return res;
}
