#pragma once

#include "IRenderer.h"

namespace sm
    {
    class TerminalRenderer : public IRenderer
    {
    public:
        ~TerminalRenderer() = default;

        void renderGameState(const GameState& state) const override;
        void renderMarket(const Market& market) const override;
        void renderMessage(const Result& result) const override;

    private:

    };
}
