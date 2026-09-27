#pragma once

#include "IRenderer.h"
#include "world/Market.h"
#include "domain/Result.h"

namespace sm
    {
    class TerminalRenderer : public IRenderer
    {
    public:
        ~TerminalRenderer() = default;

        virtual void renderState(const Player& player, const Galaxy& galaxy, int current_system_id) const override;
        virtual void renderMarket(const Market& market) const override;
        virtual void renderMessage(const Result& result) const override;
        virtual void renderMenu() const override;
        virtual void renderAvailableActions(const std::vector<Command>& actions) const override;

    private:

    };
}
