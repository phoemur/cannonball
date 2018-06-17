#include "bullet.h"

#include <cmath>

static const double PI = std::atan(1)*4;

Bullet::Bullet(double x, double y, double speed, double degrees)
    : t{}, mPosX{x}, mPosY{y}, mVelX{0}, mVelY{0}, mAccelX{0}, mAccelY{0.098}, collider{}, particles{nullptr}
{
    t.loadFromFile("./cannonball_assets/bullet.png");

    // Init collider
    collider.r = t.getWidth() / 2;
    shiftCollider();

    // Init speeds
    auto deg = degrees * PI / 180.0;
    mVelX = std::cos(deg) * speed * -1;
    mVelY = std::sin(deg) * speed * -1;

    // Init particles
    red.loadFromFile("./cannonball_assets/red.png");
    gray.loadFromFile("./cannonball_assets/gray.png");
    white.loadFromFile("./cannonball_assets/white.png");
    for (auto& part: particles) {
        part = std::make_unique<Particle>(mPosX, mPosY, &gray, &white, &red);
    }

}

void Bullet::render()
{
    t.render(static_cast<int>(mPosX - collider.r),
             static_cast<int>(mPosY - collider.r));

    renderParticles();
}

void Bullet::move()
{
    mPosX += mVelX;
    mPosY += mVelY;
    mVelY += mAccelY;
    mVelX += mAccelX;

    shiftCollider();
}

void Bullet::shiftCollider()
{
    collider.x = static_cast<int>(mPosX);
    collider.y = static_cast<int>(mPosY);
}

void Bullet::renderParticles()
{
    for (auto& part: particles) {
        if (part->isDead()) {
            part.reset(nullptr);
            part = std::make_unique<Particle>(mPosX, mPosY, &gray, &white, &red);
        }

        part->render();
    }
}
