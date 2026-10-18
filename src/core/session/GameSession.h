#pragma once

#include <QObject>
#include <memory>
#include "entities/Player.h"
#include "world/Galaxy.h"
#include "domain/GameStatus.h"
#include "context/IContext.h"
#include "pricing/StandardPricing.h"

namespace sm
{
    class GameSession : public QObject
    {
        Q_OBJECT

    public:
        explicit GameSession(QObject* parent = nullptr);

        [[nodiscard]] Planet& getCurrentPlanet();
        [[nodiscard]] const Planet& getCurrentPlanet() const;

    public slots:
        void initialize();
        void onTravelRequested(int target_system_id);
        void onBuyRequested(Commodity commodity, int quantity);
        void onSellRequested(Commodity commodity, int quantity);
        void onContextChangeRequested(ContextType context_type);
        void onActionCompleted(const Result& result);
        void onStateChanged();

    signals:
        void stateChanged(const Player& player, const Galaxy& galaxy, int current_system_id);
        void messageReceived(const QString& message);
        void gameOver();

    private:
        void switchContext(std::unique_ptr<IContext> context);

        StandardPricing m_pricing;
        Player m_player;
        Galaxy m_galaxy;        
        int m_current_system_id{0};
        int m_current_planet_id{0}; // TODO: player choice
        GameStatus m_status{GameStatus::Playing};
        std::unique_ptr<IContext> m_context;
    };
}
