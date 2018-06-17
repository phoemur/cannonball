#include "bullet.h"

#include <cmath>

static const double PI = std::atan(1)*4;

Bullet::Bullet(double x, double y, double speed, double degrees)
    : t{}, mPosX{x}, mPosY{y}, mVelX{0}, mVelY{0}, mAccelX{0}, mAccelY{0.098}, collider{}
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
    for (int i=0; i<10; ++i) {
        particles[i] = new Particle(mPosX, mPosY, &gray, &white, &red);
    }

}

Bullet::~Bullet() noexcept
{
    for (int i=0; i<10; ++i) {
        delete particles[i];
    }
}

void Bullet::render()
{
    t.render( mPosX - collider.r, mPosY - collider.r );

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
    collider.x = mPosX;
    collider.y = mPosY;
}

void Bullet::renderParticles()
{
    for (int i=0; i<10; ++i) {
        if (particles[i]->isDead()) {
            delete particles[i];
            particles[i] = new Particle(mPosX, mPosY, &gray, &white, &red);
        }
    }

    for (int i=0; i<10; ++i) {
        particles[i]->render();
    }
}
