#include "background.h"

Background::Background(const std::string& path)
    : t{}, scrollingOffset{0}
{
    t.loadFromFile(path);
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
