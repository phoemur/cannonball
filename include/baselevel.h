#ifndef BASELEVEL_H
#define BASELEVEL_H


#include "gamestate.h"
#include "mainwindow.h"
#include "texture.h"
#include "cannon.h"
#include "house.h"
#include "music.h"
#include "bullet.h"

#include <SDL.h>
#include <memory>
#include <vector>

class BaseLevel : public GameState {
protected:
    MainWindow& win;
    Texture background;
    std::vector<SDL_Rect> ground;
    Cannon cannon;
    House house;
    Sound sound;
    std::unique_ptr<Bullet> bullet {nullptr};
public:
    BaseLevel();
    virtual void handle_events() override = 0;
    virtual void logic() override = 0;
    virtual void render() override;
};

#endif // BASELEVEL_H
