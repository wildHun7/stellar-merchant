#pragma once

#include "IInputHandler.h"

namespace sm
{
    class TerminalInput : public IInputHandler
    {
    public:
        ~TerminalInput() = default;

        virtual Command getCommand() const override;
        virtual int getSystemId() const override;
        virtual Commodity getCommodity() const override;
        virtual int getQuantity() const override;
        virtual ShipType getShipType() const override;

    };
}
