#pragma once

#include "domain/Result.h"
#include "entities/Player.h"
#include "entities/Ship.h"
#include "world/Galaxy.h"
#include <vector>

namespace sm
{
    class TravelSystem
    {
    public:
        TravelSystem() = default;

        [[nodiscard]] std::vector<int> getRoute(const Galaxy& galaxy, int from_id, int to_id) const;
        [[nodiscard]] float getTravelCost(const Galaxy& galaxy, const Ship& ship, int from_id, int to_id) const;
        [[nodiscard]] Result travel(Player& player, const Galaxy& galaxy, int from_id, int target_system_id);
    };
}
