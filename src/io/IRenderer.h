#pragma once

// #include "world/Galaxy.h"
// #include "entities/Player.h"
#include "world/Market.h"
#include "domain/Result.h"

namespace sm
{
    class GameSession; // forward declaration
    // TODO: consider passing Player& and Galaxy& separately
    // to avoid upward dependency on GameSession
    // virtual void renderState(const Player& player, const Galaxy& galaxy, int currentSystemId) const = 0;

    class IRenderer
    {
    public:
        virtual ~IRenderer() = default;

        virtual void renderGameState(const GameSession& state) const = 0; // inc. Galaxy and Player
        virtual void renderMarket(const Market& market) const = 0;
        virtual void renderMessage(const Result& result) const = 0;

    };
}
