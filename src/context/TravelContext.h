#pragma once

#include "IContext.h"
#include "systems/TravelSystem.h"

namespace sm
    {
    class TravelContext : public IContext
    {
        Q_OBJECT
    public:
        explicit TravelContext(int target_system_id, QObject* parent = nullptr);

    public slots:
        void onEnter(Player& player, const Galaxy& galaxy, int current_system_id) override;

    private:
        TravelSystem m_travel_system;
        int m_target_system_id;
    };
}
