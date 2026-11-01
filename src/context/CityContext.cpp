#include "CityContext.h"

namespace sm
{
    CityContext::CityContext(Planet& planet, QObject* parent)
    :   IContext(parent)
    ,   m_planet(planet)
    {   }


    void CityContext::onTravelRequested(sm::Player&, const sm::Galaxy&, int, int target_system_id)
    {
        emit departureRequested(target_system_id);
    }

    void CityContext::onBuyRequested(sm::Player& player, sm::Planet& planet, sm::Commodity commodity, int quantity)
    {
        auto result = m_trade_system.buyCommodity(player, planet, commodity, quantity);

        emit actionCompleted(result);
        emit stateChanged();
    }

    void CityContext::onSellRequested(sm::Player& player, sm::Planet& planet, sm::Commodity commodity, int quantity)
    {
        auto result = m_trade_system.sellCommodity(player, planet, commodity, quantity);

        emit actionCompleted(result);
        emit stateChanged();
    }

}