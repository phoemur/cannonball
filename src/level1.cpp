#include "level1.h"
#include "mainwindow.h"
#include "bullet.h"
#include "gamestate.h"
#include "font.h"
#include "texture.h"

#include <SDL.h>
#include <memory>

Level1::Level1()
{
    SDL_Rect r;
    r.x = 0;
    r.y = win.getHeight() - 40;
    r.h = 40;
    r.w = win.getWidth();
    ground.push_back(std::move(r));

    cannon.setPos(win.getWidth() - 70, win.getHeight() - 65);
    cannon.setPower(8.0);
    house.setPos(70, win.getHeight() - 70);
}

void Level1::logic()
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
            temp.loadFromRenderedText("You hit it!!!! Get ready for level 2...", f, SDL_Color{0xFF,0,0,0xFF});
            background.render();
            temp.render((win.getWidth() - temp.getWidth()) / 2, (win.getHeight() - temp.getHeight()) / 2);
            win.update();
            SDL_Delay(2000);

            GameState::next_state = GameStates::Level2;
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
