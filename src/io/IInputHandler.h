#pragma once

#include "Command.h"

namespace sm
{
    class IInputHandler
    {
    public:
        virtual ~IInputHandler() = default;

        virtual Command getCommand() = 0;
        virtual int getInt() = 0; // e.g. ID or amount

    };
}
