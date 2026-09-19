#pragma once

#include "world/Galaxy.h"
#include "entities/Player.h"
#include "world/Market.h"
#include "domain/Result.h"
#include "Command.h"

namespace sm
{
    class IRenderer
    {
    public:
        virtual ~IRenderer() = default;

        virtual void renderState(const Player& player, const Galaxy& galaxy, int current_system_id) const = 0;
        virtual void renderMarket(const Market& market) const = 0;
        virtual void renderMessage(const Result& result) const = 0;
        virtual void renderAvailableActions(const std::vector<Command>& actions) const = 0;
    };
}
