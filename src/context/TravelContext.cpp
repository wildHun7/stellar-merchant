#include <QDebug>
#include "TravelContext.h"

namespace sm
{
    TravelContext::TravelContext(int target_system_id, QObject* parent)
    :   IContext(parent)
    ,   m_target_system_id(target_system_id)
    {   }

    void TravelContext::onEnter(Player& player, const Galaxy& galaxy, int current_system_id)
    {
        auto result = m_travel_system.travel(player, galaxy, current_system_id, m_target_system_id);
        emit actionCompleted(result);

        if (result.success)
            emit systemChanged(m_target_system_id);   // zawsze przed zmianą kontekstu

        emit contextChangeRequested(ContextType::City);  // po porażce wracamy do tego samego układu
    }

}