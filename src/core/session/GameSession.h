#pragma once

#include <QObject>
#include <memory>
#include "entities/Player.h"
#include "world/Galaxy.h"
#include "domain/GameStatus.h"
#include "context/IContext.h"

namespace sm
{
    class GameSession : public QObject
    {
        Q_OBJECT

    public:
        explicit GameSession(Player player, Galaxy galaxy, QObject* parent = nullptr);

    public slots:
        void onTravelRequested(int target_system_id);
        //void onBuyRequested();
        //void onSellRequested();
        void onContextChangeRequested(ContextType context_type);
        void onActionCompleted(const Result& result);
        void onStateChanged();

    signals:
        void stateChanged(const Player& player, const Galaxy& galaxy, int current_system_id);
        void messageReceived(const QString& message);
        void gameOver();

    private:
        void switchContext(std::unique_ptr<IContext> context);

        Galaxy m_galaxy;
        Player m_player;
        int m_current_system_id{0};
        GameStatus m_status{GameStatus::Playing};
        std::unique_ptr<IContext> m_context;

    };
}
