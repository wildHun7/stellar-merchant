#include "Market.h"
//#include <ranges>
#include <algorithm>

namespace sm
{
    Market::Market(PlanetType planet, float dist_from_capital,
               IPricingStrategy& pricing, unsigned int seed)
        : m_planet_type(planet)
        , m_dist_from_capital(dist_from_capital)
        , m_pricing(pricing)
        , m_gen(seed)
    {
        refreshPrices();
    }

    int Market::getPrice(Commodity cmdty) const
    {
        auto it = m_prices.find(cmdty);

        if(it == m_prices.end())
          return 0;

        return it->second;
    }

    void Market::refreshPrices()
    {
        std::uniform_real_distribution<float> noise(0.8f, 1.2f);

        std::ranges::for_each(kCommodities, [&](const CommodityInfo& info){
            float base = m_pricing.calculatePrice(info.type, m_planet_type, m_dist_from_capital);
            m_prices[info.type] = static_cast<int>(base * noise(m_gen));
        });
    }
}