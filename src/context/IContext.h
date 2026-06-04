#pragma once

#include "entities/Player.h"
#include "world/Galaxy.h"
#include "io/Command.h"
#include <vector>
#include <memory>

namespace sm
    {
    class IContext
    {
    public:
        virtual ~IContext() = default;

        virtual std::unique_ptr<IContext> update(Player& player, Galaxy& galaxy) = 0;
        virtual std::vector<Command> getAvailableActions() const = 0;
    };
}
