#include "cannon.h"

#include <SDL.h>
#include <cmath>
#include "mainwindow.h"

Cannon::Cannon()
    : mPosX{0}, mPosY{0}, degrees{0.0}, body{}, foot{}
{
    body.loadFromFile("./cannonball_assets/cannon.png");
    foot.loadFromFile("./cannonball_assets/cannon_foot.png");
}

void Cannon::setPos(int x, int y)
{
    mPosX = x;
    mPosY = y;
}

void Cannon::render()
{
    SDL_Point flip_point {(body.getWidth() / 2) + 10, body.getHeight() / 2};
    body.render(mPosX-20, mPosY-7, nullptr, degrees, &flip_point);
    foot.render(mPosX, mPosY);
}

void Cannon::handle_event(SDL_Event& e)
{
    if( e.type == SDL_KEYDOWN ) {
        switch( e.key.keysym.sym ) {
            case SDLK_UP:
            case SDLK_w:
                if (degrees < 90) {degrees += 1.0;}
                else {degrees -= 1.0;}
                break;
            case SDLK_RIGHT:
            case SDLK_d:
                if (degrees < 180) {degrees += 1.0;}
                break;
            case SDLK_DOWN:
            case SDLK_s:
                if (degrees <= 90 && degrees > 0) {degrees -= 1.0;}
                else if (degrees < 180) {degrees += 1.0;}
                break;
            case SDLK_LEFT:
            case SDLK_a:
                if (degrees > 0) {degrees -= 1.0;}
                break;
            default:
                break;
        }
    }
    else if (e.type == SDL_MOUSEMOTION) {
        static double pi = std::atan(1) * 4;

        //Get mouse position
        int x, y;
        SDL_GetMouseState( &x, &y );
        auto oposed = mPosY - y;
        auto hyp = std::hypot(mPosX - x, mPosY - y);
        degrees = (std::asin(oposed / hyp) * 180) / pi;
        if (x > mPosX) {
            degrees = 180 - degrees;
        }

    }
}

SDL_Rect Cannon::getCollider()
{
    SDL_Rect res;
    res.x = mPosX;
    res.y = mPosY;
    res.w = foot.getWidth();
    res.h = foot.getHeight();

    return res;
}

std::unique_ptr<Bullet> Cannon::fire(double speed)
{
    return std::make_unique<Bullet>(mPosX + 9, mPosY + 4, speed, degrees);
}

