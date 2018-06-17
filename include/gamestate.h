#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "bullet.h"

#include <memory>

enum class GameStates {
    Intro,
    Level1,
    Level2,
    Level3,
    Level4,
    Level5,
    Won,
    Quit,
    Null
};

class GameState {
public:
    virtual void handle_events() = 0;
    virtual void logic() = 0;
    virtual void render() = 0;
    virtual ~GameState() noexcept;

    // Current game state
    static GameStates curr_state;
    static GameStates next_state;
};

void changeState(std::unique_ptr<GameState>& state);
bool hasValidPos(const std::unique_ptr<Bullet>& ptr);
bool checkCollision(const Circle& a, const Circle& b);
bool checkCollision(const Circle& a, const SDL_Rect& b);
bool checkCollision(const SDL_Rect& a, const SDL_Rect& b);
double distanceSquared(int x1, int y1, int x2, int y2);

#endif // GAMESTATE_H
