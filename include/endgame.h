#ifndef ENDGAME_H
#define ENDGAME_H

#include "gamestate.h"
#include "mainwindow.h"
#include "texture.h"
#include "font.h"

class EndGame : public GameState {
    MainWindow& win;
    Texture background;
    Texture title;
    Texture subtitle;
    Texture copyright;
    Font f1, f2, f3;
public:
    EndGame();
    virtual void handle_events() override;
    virtual void logic() override;
    virtual void render() override;
};

#endif // ENDGAME_H
