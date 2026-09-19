#pragma once
#include "IContext.h"

namespace sm
{
    class QuitContext : public IContext
    {
        std::unique_ptr<IContext> update(Player&, Galaxy&, int) override
        {
            return nullptr;
        }

        std::vector<Command> getAvailableActions() const override
        {
            return {};
        }

        bool wantsToQuit() const override
        {
            return true;
        }
    };
}