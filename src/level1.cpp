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
    house.setPos(70, win.getHeight() - 70);
}

void Level1::handle_events()
{
    SDL_Event e;

    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            GameState::next_state = GameStates::Quit;
        }
        else if (e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_SPACE || e.key.keysym.sym == SDLK_RETURN)) {
            if (bullet == nullptr) {
                // fire
                sound.play();
                bullet = cannon.fire(8.0);
            }
        }
        else if (e.type == SDL_MOUSEBUTTONDOWN) {
            if (bullet == nullptr) {
                // fire
                sound.play();
                bullet = cannon.fire(8.0);
            }
        }
        else {
            // Let the Cannon Handle his movements
            cannon.handle_event(e);
        }
    }
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
            background.render(0,0);
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
