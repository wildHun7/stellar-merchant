#pragma once
#include "IInputHandler.h"
#include <QObject>

namespace sm
{
    class GameWindow; // forward declaration

    class QtInputHandler : public QObject, public IInputHandler
    {
        Q_OBJECT

    public:
        explicit QtInputHandler(GameWindow& window);

        Command getCommand() const override;
        int getSystemId() const override;
        Commodity getCommodity() const override;
        int getQuantity() const override;
        ShipType getShipType() const override;
        MenuOption getMenuOption() const override;

    private:
        GameWindow& m_game_window;
        };
}