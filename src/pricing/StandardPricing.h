#pragma once

#include "IPricingStrategy.h"
#include "domain/Commodity.h"
#include "domain/PlanetType.h"
//#include <random>

namespace sm
{
    class StandardPricing : public IPricingStrategy
    {
    public:
        ~StandardPricing() = default;

        int calculatePrice(Commodity cmdty_type, PlanetType planet, float dist) const override;

    private:
        //std::mt19937 m_gen;
    };
}
