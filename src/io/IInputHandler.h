#pragma once

#include "Command.h"
#include "domain/Commodity.h"
#include "domain/ShipType.h"

namespace sm
{
    class IInputHandler
    {
    public:
        virtual ~IInputHandler() = default;

        virtual Command getCommand() const = 0;
        virtual int getSystemId() const = 0;
        virtual Commodity getCommodity() const = 0;
        virtual int getQuantity() const = 0;
        virtual ShipType getShipType() const = 0;

    };
}
