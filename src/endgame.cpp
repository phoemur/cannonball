#include "endgame.h"

EndGame::EndGame()
    : win{MainWindow::instance()}, background{},
      title{}, subtitle{}, copyright{}, f1{}, f2{}, f3{}
{
    f1.loadFromFile("./cannonball_assets/Purisa-BoldOblique.ttf", 30);
    f2.loadFromFile("./cannonball_assets/Purisa-BoldOblique.ttf", 16);
    f3.loadFromFile("./cannonball_assets/Purisa-BoldOblique.ttf", 12);
    title.loadFromRenderedText("You finished all levels!!!", f1, SDL_Color{0xFF,0,0,0xFF});
    subtitle.loadFromRenderedText("Thanks for playing. Press N to play again...", f2, SDL_Color{0,0,0,0xFF});
    copyright.loadFromRenderedText("Cannonball shooter 0.1.0 - copyright Fernando B. Giannasi - jun/2018", f3, SDL_Color{0,0,0,0xFF});

    background.loadFromFile("./cannonball_assets/clouds.jpg");
}

void EndGame::handle_events()
{
    SDL_Event e;

    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            GameState::next_state = GameStates::Quit;
        }
        else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_n) {
            GameState::next_state = GameStates::Level1;
        }
    }
}

void EndGame::logic() {}

void EndGame::render()
{
    win.clear();
    background.render(0, 0);
    title.render((win.getWidth() - title.getWidth()) / 2, (win.getHeight() - title.getHeight()) / 2);
    subtitle.render((win.getWidth() - subtitle.getWidth()) / 2,
                    (win.getHeight() + title.getHeight() - subtitle.getHeight()) / 2 );

    copyright.render((win.getWidth() - copyright.getWidth()) / 2,
                      win.getHeight() - (2*copyright.getHeight()));

    win.update();
}
