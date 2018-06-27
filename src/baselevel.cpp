#include "baselevel.h"

BaseLevel::BaseLevel()
    : win{MainWindow::instance()},
      background{"./cannonball_assets/clouds.jpg"},
      ground{},
      cannon{},
      house{},
      sound{"./cannonball_assets/shot.mp3"}
{

}

void BaseLevel::handle_events()
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
                bullet = cannon.fire();
            }
        }
        else if (e.type == SDL_MOUSEBUTTONDOWN) {
            if (bullet == nullptr) {
                // fire
                sound.play();
                bullet = cannon.fire();
            }
        }
        else {
            // Let the Cannon Handle his movements
            cannon.handle_event(e);
        }
    }
}

void BaseLevel::render()
{
    win.clear();
    background.render();
    background.scroll();
    for (auto& rec: ground) {
        SDL_SetRenderDrawColor( win.getRenderer(), 0xCC, 0x66, 0x00, 0xFF );
        SDL_RenderFillRect( win.getRenderer(), &rec );
    }

    cannon.render();
    house.render();
    if (bullet != nullptr) {
        bullet->render();
    }
    win.update();
}
