#pragma once

#include "Galaxy.h"

namespace sm
{
    class IMapGenerator
    {
    public:
        virtual ~IMapGenerator() = default;

        virtual Galaxy generateGalaxy(int system_count, unsigned int seed) const = 0;
    };
}
