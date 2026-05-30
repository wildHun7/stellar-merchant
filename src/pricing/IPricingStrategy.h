#pragma once

#include "domain/Commodity.h"
#include "domain/PlanetType.h"

namespace sm
{
    class IPricingStrategy
    {
    public:
        virtual ~IPricingStrategy() = default;

        virtual int calculatePrice(Commodity cmdty_type, PlanetType planet, float dist) const = 0;
    };
}
