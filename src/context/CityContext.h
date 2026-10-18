#pragma once

#include "IContext.h"
#include "systems/TradeSystem.h"
#include "world/Planet.h"

namespace sm
{
    class CityContext : public IContext
    {
        Q_OBJECT
    public:
        explicit CityContext(Planet& planet, QObject* parent = nullptr);

    public slots:
        void onTravelRequested(sm::Player& player, const sm::Galaxy& galaxy, int current_system_id, int target_system_id) override;
        void onBuyRequested(sm::Player& player, sm::Planet& planet, sm::Commodity commodity, int quantity) override;
        void onSellRequested(sm::Player& player, sm::Planet& planet, sm::Commodity commodity, int quantity) override;

    private:
        TradeSystem m_trade_system;
        Planet& m_planet;
    };
}
