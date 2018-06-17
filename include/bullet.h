#ifndef BULLET_H
#define BULLET_H

#include "texture.h"
#include "particle.h"

#include <array>
#include <memory>

//A circle stucture
struct Circle {
    int x, y;
    int r;
};

class Bullet {
    Texture t;

    double mPosX, mPosY;
    double mVelX, mVelY;
    double mAccelX, mAccelY;

    Circle collider;

    Texture red{}, white{}, gray{};

    std::array<std::unique_ptr<Particle>, 10> particles;

    void shiftCollider();
    void renderParticles();
public:
    Bullet(double x, double y, double speed, double degrees);

    void render();
    void move();

    const Circle& getCollider() const noexcept {return collider;}
    double getPos_X()const noexcept {return mPosX;}
    double getPos_Y()const noexcept {return mPosY;}
    double getSpeed_Y() const noexcept {return mVelY;}
    double getSpeed_X() const noexcept {return mVelX;}
};

#endif // BULLET_H
