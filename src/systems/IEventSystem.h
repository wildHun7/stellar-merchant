#pragma once

#include "domain/Result.h"

namespace sm
{
    class IEventSystem
    {
    public:
        virtual ~IEventSystem() = default;

        virtual Result triggerEvent()= 0;
    };
}
