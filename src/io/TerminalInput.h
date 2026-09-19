#pragma once

#include "IInputHandler.h"

namespace sm
{
    class TerminalInput : public IInputHandler
    {
    public:
        ~TerminalInput() = default;

        Command getCommand() override;
        virtual int getSystemId() const override;
        virtual Commodity getCommodity() const override;
        virtual int getQuantity() const override;

    private:

    };
}
