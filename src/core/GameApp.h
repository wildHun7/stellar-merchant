#pragma once

#include "session/GameSession.h"
#include "domain/ShipType.h"
#include <QObject>
//#include <memory>
#include <optional>
#include <qwindowdefs.h>

namespace sm
{
    class GameApp : public QObject
    {
        Q_OBJECT

    public:
        explicit GameApp(QObject* parent = nullptr);

    public slots:
        void onGameStartRequested(ShipType type);
        void onQuit();
        void onTravelRequested();
        void onBuyRequested();
        void onSellRequested();
        void onStateChanged(const Player& player, const Galaxy& galaxy, int current_system_id);
        void onMessageReceived(const QString& message);

    signals:
        void stateChanged(const Player& player, const Galaxy& galaxy, int current_system_id);
        void messageReceived(const QString& message);

    private:
        std::optional<GameSession> m_game_session;
    };
}
