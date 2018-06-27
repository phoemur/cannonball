#include "level3.h"
#include "mainwindow.h"
#include "bullet.h"
#include "gamestate.h"
#include "font.h"
#include "texture.h"

#include <SDL.h>
#include <memory>

Level3::Level3()
{
    SDL_Rect r;
    r.x = 0;
    r.y = win.getHeight() - 30;
    r.h = 30;
    r.w = win.getWidth() / 3;
    ground.push_back(std::move(r));

    r.x = win.getWidth() / 3;
    r.y = win.getHeight() - 300;
    r.h = 300;
    r.w = win.getWidth() / 3;
    ground.push_back(std::move(r));

    r.x = 2 * (win.getWidth() / 3);
    r.y = win.getHeight() - 30;
    r.h = 30;
    r.w = win.getWidth() / 3;
    ground.push_back(std::move(r));

    cannon.setPos(win.getWidth() - 60, win.getHeight() - 55);
    cannon.setPower(10.0);
    house.setPos(90, win.getHeight() - 60);
}

void Level3::logic()
{
    if (bullet != nullptr) {
        bullet->move();

        if (!hasValidPos(bullet)) {
            bullet.reset(nullptr);
            return;
        }
        else if (checkCollision(bullet->getCollider(), house.getCollider())) {
            bullet.reset(nullptr);
            win.clear();
            Texture temp{};
            Font f {"./cannonball_assets/Purisa-BoldOblique.ttf", 20};
            temp.loadFromRenderedText("You hit it!!!! Get ready for level 4...", f, SDL_Color{0xFF,0,0,0xFF});
            background.render();
            temp.render((win.getWidth() - temp.getWidth()) / 2, (win.getHeight() - temp.getHeight()) / 2);
            win.update();
            SDL_Delay(2000);

            GameState::next_state = GameStates::Level4;
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
