#include "intro.h"

#include <SDL.h>

Intro::Intro()
    : win{MainWindow::instance()}, background{}, title{}, subtitle{}, f1{}, f2{}
{
    f1.loadFromFile("./cannonball_assets/Purisa-BoldOblique.ttf", 30);
    f2.loadFromFile("./cannonball_assets/Purisa-BoldOblique.ttf", 16);
    title.loadFromRenderedText("Welcome to cannonball shooter", f1, SDL_Color{0xFF,0,0,0xFF});
    subtitle.loadFromRenderedText("Press any key to continue...", f2, SDL_Color{0,0,0,0xFF});
}

void Intro::handle_events()
{
    SDL_Event e;

    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            GameState::next_state = GameStates::Quit;
        }
        else if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN) {
            GameState::next_state = GameStates::Level1;
        }
    }
}

void Intro::logic() {}

void Intro::render()
{
    win.clear();
    background.render();
    background.scroll();
    title.render((win.getWidth() - title.getWidth()) / 2, (win.getHeight() - title.getHeight()) / 2);
    subtitle.render((win.getWidth() - subtitle.getWidth()) / 2,
                    (win.getHeight() + title.getHeight() - subtitle.getHeight()) / 2 );
    win.update();
}
