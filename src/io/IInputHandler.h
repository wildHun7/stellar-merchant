#pragma once

#include "Command.h"
#include "domain/Commodity.h"

namespace sm
{
    class IInputHandler
    {
    public:
        virtual ~IInputHandler() = default;

        virtual Command getCommand() = 0;
        virtual int getSystemId() const = 0;
        virtual Commodity getCommodity() const = 0;
        virtual int getQuantity() const = 0;

    };
}
