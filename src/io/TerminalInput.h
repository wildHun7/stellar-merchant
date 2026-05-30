#pragma once

#include "IInputHandler.h"

namespace sm
{
    class TerminalInput : public IInputHandler
    {
    public:
        ~TerminalInput() = default;

        Command getCommand() override;
        int getInt() override;

    private:

    };
}
