#ifndef PARTICLE_H
#define PARTICLE_H

#include "texture.h"

class Particle {
    int mPosX, mPosY, mFrame;
    Texture* gray, *white, *red, *currTexture;

public:
    Particle(int x, int y, Texture* g, Texture* w, Texture* r);
    void render();
    bool isDead();
};

#endif // PARTICLE_H
