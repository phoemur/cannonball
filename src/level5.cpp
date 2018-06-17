#include "level5.h"
#include "mainwindow.h"
#include "bullet.h"
#include "gamestate.h"
#include "font.h"
#include "texture.h"

#include <SDL.h>
#include <memory>

Level5::Level5()
{
    SDL_Rect r;
    r.x = 0;
    r.y = win.getHeight() - 200;
    r.h = 200;
    r.w = win.getWidth() / 4;
    ground.push_back(std::move(r));

    r.x = 2 * (win.getWidth() / 4);
    r.y = win.getHeight() - 400;
    r.h = 400;
    r.w = win.getWidth() / 4;
    ground.push_back(std::move(r));

    r.x = 3 * (win.getWidth() / 4);
    r.y = win.getHeight() - 30;
    r.h = 30;
    r.w = win.getWidth() / 4;
    ground.push_back(std::move(r));

    cannon.setPos(60, win.getHeight() - 225);
    cannon.setPower(10.0);
    house.setPos(win.getWidth() - 70, win.getHeight() - 60);
}


void Level5::logic()
{
    if (bullet != nullptr) {
        bullet->move();

        if (!hasValidPos(bullet)) {
            bullet.reset(nullptr);
            return;
        }
        else if (checkCollision(bullet->getCollider(), house.getCollider())) {
            bullet.reset(nullptr);
            GameState::next_state = GameStates::Won;
            return;
        }
        else {
            for (auto& rec: ground) {
                if (checkCollision(bullet->getCollider(), rec)) {
                    bullet.reset(nullptr);
                    return;
                }
            }
        }
    }
}
