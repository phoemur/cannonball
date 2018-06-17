#include "mainwindow.h"
#include "exception.h"
#include "music.h"

#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>

// Static data
int MainWindow::height = 0;
int MainWindow::width = 0;
std::string MainWindow::title = " ";
std::string MainWindow::icon_path = "";

MainWindow::MainWindow()
    : gWindow{nullptr}, gRenderer{nullptr}, music{nullptr}
{
    int res = SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    if (res < 0) {throw CannonException(std::string("SDL could not initialize! SDL Error: ") + SDL_GetError());}

    res = SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    if (!res) {std::cerr << "Warning: Linear texture filtering not enabled!" << std::endl;}

    gWindow = SDL_CreateWindow( title.c_str(),
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                width,
                                height,
                                SDL_WINDOW_SHOWN );

    if (gWindow == nullptr) {
        throw CannonException(std::string("Could not create Window! SDL Error: ") + SDL_GetError());
    }

    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    if (gRenderer == nullptr) {
        throw CannonException(std::string("Renderer could not be created! SDL Error: ") + SDL_GetError());
    }

    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    res = IMG_INIT_JPG | IMG_INIT_PNG;
    if( !( IMG_Init( res ) & res ) ) {
        throw CannonException(std::string("SDL_image could not initialize! SDL_image Error: ") + IMG_GetError());
    }

    res = TTF_Init();
    if (res == -1) {
        throw CannonException(std::string("SDL_ttf could not initialize! SDL_ttf Error: ") + TTF_GetError());
    }

    res = Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
    if (res < 0) {
        throw CannonException(std::string("SDL_mixer could not initialize! SDL_mixer Error: ") + Mix_GetError());
    }

    if (icon_path.size() > 0) {makeIcon();}

    music = new Music("./cannonball_assets/batistademelo.mp3");
    music->play();
}

MainWindow::~MainWindow() noexcept
{
    delete music;

    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );

    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

MainWindow& MainWindow::instance()
{
    static MainWindow the_instance {};

    return the_instance;
}

void MainWindow::makeIcon()
{
    SDL_Surface* icon = IMG_Load(icon_path.c_str());
    if (icon == nullptr) {
        throw CannonException(std::string("Could not load Icon! SDL_image Error: ") + IMG_GetError());
    }
    SDL_SetWindowIcon(gWindow, icon);
    SDL_FreeSurface(icon); // icon is no longer required
}

void MainWindow::clear()
{
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( gRenderer );
}

void MainWindow::update()
{
    SDL_RenderPresent( gRenderer );
}
