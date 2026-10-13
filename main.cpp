#include "core/GameApp.h"
#include "io/GameWindow.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    sm::GameWindow game_window;
    sm::GameApp game_app{};

    // GameWindow → GameApp (model update)
    QObject::connect(&game_window, &sm::GameWindow::newGameRequested, &game_app, &sm::GameApp::onNewGame);
    QObject::connect(&game_window, &sm::GameWindow::quitRequested, &game_app, &sm::GameApp::onQuit);
    QObject::connect(&game_window, &sm::GameWindow::travelRequested, &game_app, &sm::GameApp::onTravelRequested);

    // GameApp → GameWindow (GUI update)
    QObject::connect(&game_app, &sm::GameApp::stateChanged, &game_window, &sm::GameWindow::onStateChanged);
    QObject::connect(&game_app, &sm::GameApp::messageReceived, &game_window, &sm::GameWindow::onMessageReceived);

    game_window.show();

    return app.exec();
}



