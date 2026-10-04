#include "QtInputHandler.h"
#include "QEventLoop"
#include "QPushButton"
#include "Command.h"
#include "GameWindow.h"
#include "QInputDialog"

namespace sm
{
    QtInputHandler::QtInputHandler(GameWindow& window)
        : QObject(nullptr)
        , m_game_window(window)
    {   }

    Command QtInputHandler::getCommand() const
    {
        QEventLoop loop;
        Command result = Command::Quit;

        connect(m_game_window.getTravelButton(), &QPushButton::clicked, [&]() {
            result = Command::Travel;
            loop.quit();
        });
        connect(m_game_window.getBuyButton(), &QPushButton::clicked, [&]() {
            result = Command::Buy;
            loop.quit();
        });
        connect(m_game_window.getSellButton(), &QPushButton::clicked, [&]() {
            result = Command::Sell;
            loop.quit();
        });
        connect(m_game_window.getQuitButton(), &QPushButton::clicked, [&]() {
            result = Command::Quit;
            loop.quit();
        });

        loop.exec();

        disconnect(m_game_window.getTravelButton(), nullptr, nullptr, nullptr);
        disconnect(m_game_window.getBuyButton(), nullptr, nullptr, nullptr);
        disconnect(m_game_window.getSellButton(), nullptr, nullptr, nullptr);
        disconnect(m_game_window.getQuitButton(), nullptr, nullptr, nullptr);

        return result;
    }

    int QtInputHandler::getSystemId() const
    {
        bool ok;
        int id = QInputDialog::getInt(
            nullptr,            // parent
            "Travel",           //
            "Enter System ID:", //
            0,                  // def val
            0,                  // min
            100,                // max
            1,                  // step
            &ok
            );

        if (ok) return id;
        return 0; // anulowano
    }

    Commodity QtInputHandler::getCommodity() const
    {

    }

    int QtInputHandler::getQuantity() const
    {
        bool ok;
        int id = QInputDialog::getInt(
            nullptr,            // parent
            "Trade",            //
            "Enter Quantity:",  //
            0,                  // def val
            0,                  // min
            1000,               // max
            1,                  // step
            &ok
            );

        if (ok) return id;
        return 0;
    }

    ShipType QtInputHandler::getShipType() const
    {

    }

    MenuOption getMenuOption() const
    {
        QEventLoop loop;
        MenuOption result = MenuOption::Quit;

        connect(m_game_window.getNewGameButton(), &QPushButton::clicked, [&]() {
            result = MenuOption::NewGame;
            loop.quit();
        });
        connect(m_game_window.getQuitButton(), &QPushButton::clicked, [&]() {
            result = MenuOption::Quit;
            loop.quit();
        });

        loop.exec();

        disconnect(m_game_window.getNewGameButton(), nullptr, nullptr, nullptr);
        disconnect(m_game_window.getQuitButton(), nullptr, nullptr, nullptr);

        return result;
    }
}