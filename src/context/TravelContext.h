#pragma once

#include "IContext.h"
#include "systems/TravelSystem.h"
#include "io/IInputHandler.h"
#include "io/IRenderer.h"

namespace sm
{
    class TravelContext : public IContext
    {
    public:
        explicit TravelContext(IRenderer& renderer, IInputHandler& input);
        ~TravelContext() = default;

        std::unique_ptr<IContext> update(Player& player, Galaxy& galaxy) override;
        std::vector<Command> getAvailableActions() const override;

    private:
        TravelSystem m_travel_system;
        int m_target_system_id;
        IRenderer& m_renderer;
        IInputHandler& m_input;

    };
}
