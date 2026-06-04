#pragma once

#include "IRenderer.h"
#include "core/session/GameSession.h"
#include "world/Market.h"
#include "domain/Result.h"

namespace sm
    {
    class TerminalRenderer : public IRenderer
    {
    public:
        ~TerminalRenderer() = default;

        void renderGameState(const GameSession& state) const override;
        void renderMarket(const Market& market) const override;
        void renderMessage(const Result& result) const override;

    private:

    };
}
