#include "background.h"

Background::Background()
    : t{}, scrollingOffset{0}
{
    t.loadFromFile("./cannonball_assets/clouds.jpg");
}

void Background::render()
{
    // Render 2 copies
    t.render(scrollingOffset, 0);
    t.render(scrollingOffset - t.getWidth(), 0);
}

void Background::scroll()
{
    ++scrollingOffset;
    if( scrollingOffset > t.getWidth()) { scrollingOffset = 0; }
}
