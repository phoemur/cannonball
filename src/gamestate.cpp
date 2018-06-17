#include "gamestate.h"
#include "intro.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "level5.h"
#include "endgame.h"

GameStates GameState::curr_state = GameStates::Intro;
GameStates GameState::next_state = GameStates::Null;
GameState::~GameState() noexcept = default;

void changeState(std::unique_ptr<GameState>& state)
{
    if (GameState::next_state != GameStates::Null) {
        switch (GameState::next_state) {
            case GameStates::Intro:
                state.reset(nullptr);
                state = std::make_unique<Intro>();
                break;
            case GameStates::Quit:
                state.reset(nullptr);
                break;
            case GameStates::Level1:
                state.reset(nullptr);
                state = std::make_unique<Level1>();
                break;
            case GameStates::Level2:
                state.reset(nullptr);
                state = std::make_unique<Level2>();
                break;
            case GameStates::Level3:
                state.reset(nullptr);
                state = std::make_unique<Level3>();
                break;
            case GameStates::Level4:
                state.reset(nullptr);
                state = std::make_unique<Level4>();
                break;
            case GameStates::Level5:
                state.reset(nullptr);
                state = std::make_unique<Level5>();
                break;
            case GameStates::Won:
                state.reset(nullptr);
                state = std::make_unique<EndGame>();
                break;
            default:
                break;
        }

        GameState::curr_state = GameState::next_state;
        GameState::next_state = GameStates::Null;
    }
}

bool hasValidPos(const std::unique_ptr<Bullet>& ptr)
{
    auto& win = MainWindow::instance();
    if (ptr->getPos_X() > win.getWidth() || ptr->getPos_X() < 0) {
        return false;
    }
    else if (ptr->getPos_Y() > win.getHeight()) { // Above is valid
        return false;
    }
    else {
        return true;
    }
}

bool checkCollision(const Circle& a, const Circle& b)
{
    //Calculate total radius squared
    int totalRadiusSquared = a.r + b.r;
    totalRadiusSquared = totalRadiusSquared * totalRadiusSquared;

    //If the distance between the centers of the circles is less than the sum of their radii
    if( distanceSquared( a.x, a.y, b.x, b.y ) < ( totalRadiusSquared ) ) {
        //The circles have collided
        return true;
    }

    //If not
    return false;
}

bool checkCollision(const Circle& a, const SDL_Rect& b)
{
    //Closest point on collision box
        int cX, cY;

        //Find closest x offset
        if(a.x < b.x) {
            cX = b.x;
        }
        else if (a.x > b.x + b.w) {
            cX = b.x + b.w;
        }
        else {
            cX = a.x;
        }

        //Find closest y offset
        if(a.y < b.y) {
            cY = b.y;
        }
        else if (a.y > b.y + b.h) {
            cY = b.y + b.h;
        }
        else {
            cY = a.y;
        }

        //If the closest point is inside the circle
        if(distanceSquared(a.x, a.y, cX, cY) < a.r * a.r) {
            //This box and the circle have collided
            return true;
        }

        //If the shapes have not collided
        return false;
}

bool checkCollision(const SDL_Rect& a, const SDL_Rect& b)
{
    //If any of the sides from A are outside of B
    if( a.y + a.h <= b.y ) { return false; }
    if( a.y >= b.y + b.h ) { return false; }
    if( a.x + a.w <= b.x ) { return false; }
    if( a.x >= b.x + b.w ) { return false; }

    //If none of the sides from A are outside B
    return true;
}

double distanceSquared(int x1, int y1, int x2, int y2)
{
    int deltaX = x2 - x1;
    int deltaY = y2 - y1;
    return deltaX*deltaX + deltaY*deltaY;
}
