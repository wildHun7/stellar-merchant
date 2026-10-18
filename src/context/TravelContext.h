#pragma once

#include "IContext.h"
#include "systems/TravelSystem.h"

namespace sm
    {
    class TravelContext : public IContext
    {
        Q_OBJECT
    public:
        explicit TravelContext(QObject* parent = nullptr);

    public slots:
        void onTravelRequested(sm::Player& player, const sm::Galaxy& galaxy, int current_system_id, int target_system_id) override;

    private:
        TravelSystem m_travel_system;
    };
}
