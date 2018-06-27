#ifndef INTRO_H
#define INTRO_H

#include "gamestate.h"
#include "mainwindow.h"
#include "texture.h"
#include "background.h"
#include "font.h"


class Intro : public GameState {
    MainWindow& win;
    Background background;
    Texture title;
    Texture subtitle;
    Font f1, f2;
public:
    Intro();
    virtual void handle_events() override;
    virtual void logic() override;
    virtual void render() override;
};

#endif // INTRO_H
