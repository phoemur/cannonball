#include "level2.h"
#include "mainwindow.h"
#include "bullet.h"
#include "gamestate.h"
#include "font.h"
#include "texture.h"

#include <SDL.h>
#include <memory>

Level2::Level2()
{
    SDL_Rect r;
    r.x = 0;
    r.y = win.getHeight() - 300;
    r.h = 300;
    r.w = win.getWidth() / 2;
    ground.push_back(std::move(r));

    r.x = win.getWidth() / 2;
    r.y = win.getHeight() - 30;
    r.h = 30;
    r.w = win.getWidth() / 2;
    ground.push_back(std::move(r));

    cannon.setPos(win.getWidth() - 60, win.getHeight() - 55);
    cannon.setPower(10.0);
    house.setPos(70, win.getHeight() - 330);
}

void Level2::logic()
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
            temp.loadFromRenderedText("You hit it!!!! Get ready for level 3...", f, SDL_Color{0xFF,0,0,0xFF});
            background.render(0,0);
            temp.render((win.getWidth() - temp.getWidth()) / 2, (win.getHeight() - temp.getHeight()) / 2);
            win.update();
            SDL_Delay(2000);

            GameState::next_state = GameStates::Level3;
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
