#ifndef CANNON_H
#define CANNON_H

#include "texture.h"
#include "bullet.h"

#include <SDL.h>
#include <memory>

class Cannon {
    int mPosX, mPosY;
    double degrees;
    double power;
    Texture body;
    Texture foot;
    SDL_Rect collider;
public:
    Cannon();
    void setPos(int x, int y);
    void setPower(double p);
    void render();
    void handle_event(SDL_Event& e);
    const SDL_Rect& getCollider() const noexcept {return collider;}
    std::unique_ptr<Bullet> fire();
};

#endif // CANNON_H
