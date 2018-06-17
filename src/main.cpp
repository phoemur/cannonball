#include "mainwindow.h"
#include "timer.h"
#include "gamestate.h"
#include "intro.h"

#include <memory>

int main()
{
    MainWindow::setSize(640, 480);
    MainWindow::setTitle("CannonBall Shooter");
    MainWindow::setIcon("./cannonball_assets/icon.png");

    std::unique_ptr<GameState> currentState {std::make_unique<Intro>()};

    // Game main loop
    while (GameState::curr_state != GameStates::Quit) {
        currentState->handle_events();
        currentState->logic();
        currentState->render();

        changeState(currentState);

        Timer::capFrameRate(60);
    }

    return 0;
}
