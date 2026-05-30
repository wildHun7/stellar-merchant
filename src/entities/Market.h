#pragma once

#include "domain/Commodity.h"
#include "domain/PlanetType.h"
#include "pricing/IPricingStrategy.h"
#include <unordered_map>

namespace sm
{
    class Market
    {
    public:
        explicit Market(PlanetType planet, float dist_from_capital, IPricingStrategy& pricing);

        [[nodiscard]] int getPrice(Commodity cmdty_type) const;
        void refreshPrices();

    private:
        PlanetType m_planet;
        float m_dist_from_capital;
        IPricingStrategy& m_pricing;
        std::unordered_map<Commodity, int> m_prices;
    };
}
