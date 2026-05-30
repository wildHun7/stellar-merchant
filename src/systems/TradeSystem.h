#pragma once

#include "domain/Commodity.h"
#include "domain/Result.h"
#include "entities/Player.h"
#include "world/Planet.h"

namespace sm
    {
    class TradeSystem
    {
    public:
        TradeSystem() = default;

        [[nodiscard]] Result buyCommodity(Player& player, const Planet& planet, Commodity cmdty, int amount);
        [[nodiscard]] Result sellCommodity(Player& player, const Planet& planet, Commodity cmdty, int amount);
    };
}
