#pragma once

#include "CommodityType.h"
#include "PlanetType.h"

class IPricingStrategy
{
public:
    virtual ~IPricingStrategy() = default;

    virtual int calculatePrice(CommodityType cmdty_type, PlanetType planet, float dist) const = 0;
};
