#include "baselevel.h"

BaseLevel::BaseLevel()
    : win{MainWindow::instance()},
      background{},
      ground{},
      cannon{},
      house{},
      sound{"./cannonball_assets/shot.mp3"}
{
    background.loadFromFile("./cannonball_assets/clouds.jpg");
}

void BaseLevel::render()
{
    win.clear();
    background.render(0, 0);
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
