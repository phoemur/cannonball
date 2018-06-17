#include "particle.h"

#include <cstdlib>

Particle::Particle(int x, int y, Texture* g, Texture* w, Texture* r)
    : mPosX{x - 3 + ( std::rand() % 9 )},
      mPosY{y - 3 + ( std::rand() % 9 )},
      mFrame{std::rand() % 3},
      gray{g},
      white{w},
      red{r},
      currTexture{nullptr}
{
    if ( std::rand() % 2 ) {currTexture = red;}
    else {currTexture = gray;}
}

void Particle::render()
{
    currTexture->render(mPosX, mPosY);

    if( mFrame % 2 == 0 ) { white->render(mPosX, mPosY);}

    mFrame++;
}

bool Particle::isDead()
{
    return mFrame > 7;
}
