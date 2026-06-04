#pragma once

#include "IContext.h"
#include "systems/TradeSystem.h"
#include "io/IInputHandler.h"
#include "io/IRenderer.h"
#include "world/Planet.h"

namespace sm
{
    class CityContext : public IContext
    {
    public:
        explicit CityContext(Planet& planet, IRenderer& renderer, IInputHandler& input);
        ~CityContext() = default;

        std::unique_ptr<IContext> update(Player& player, Galaxy& galaxy) override;
        std::vector<Command> getAvailableActions() const override;

    private:
        TradeSystem m_trade_system;
        Planet& m_planet;
        IRenderer& m_renderer;
        IInputHandler& m_input;

    };
}
