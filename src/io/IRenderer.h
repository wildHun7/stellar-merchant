#pragma once

// #include "world/Galaxy.h"
// #include "entities/Player.h"
#include "core/GameState.h"
#include "world/Market.h"
#include "domain/Result.h"

namespace sm
{
    class IRenderer
    {
    public:
        virtual ~IRenderer() = default;

        virtual void renderGameState(const GameState& state) const = 0; // inc. Galaxy and Player
        virtual void renderMarket(const Market& market) const = 0;
        virtual void renderMessage(const Result& result) const = 0;

    };
}
