#include "TravelContext.h"
//#include "CityContext.h"

namespace sm
{
    TravelContext::TravelContext(QObject* parent)
        : IContext(parent)
    {   }

    void TravelContext::onTravelRequested(Player& player, const Galaxy& galaxy, int current_system_id, int target_system_id)
    {
        auto result = m_travel_system.travel(player, galaxy, current_system_id, target_system_id);

        emit actionCompleted(result);

        if (result.success)
            emit contextChangeRequested(ContextType::City);

        emit stateChanged();
    }

}