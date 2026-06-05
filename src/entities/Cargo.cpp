#include "Cargo.h"
#include "domain/Commodity.h"
#include <numeric>
#include <ranges>

namespace sm
{
    int Cargo::getQuantity(Commodity cmdty_type) const
    {
        auto it = m_stored_cargo.find(cmdty_type);

        if(it == m_stored_cargo.end())
            return 0;

        return it->second;
    }

    bool Cargo::addCommodity(Commodity cmdty_type, int quantity)
    {
        if(quantity <= 0)
            return false;

        m_stored_cargo[cmdty_type] += quantity;

        return true;
    }

    bool Cargo::removeCommodity(Commodity cmdty_type, int quantity)
    {
        if (quantity <= 0)
            return false;

        auto it = m_stored_cargo.find(cmdty_type);

        if (it == m_stored_cargo.end() || it->second < quantity)
            return false;

        it->second -= quantity;

        if (it->second == 0)
            m_stored_cargo.erase(it);

        return true;
    }

    float Cargo::getCurrentMass() const
    {
        namespace rv = std::ranges::views;

        auto cargo_mass_view = m_stored_cargo
        | rv::transform([](const auto& pair){       // cargo key = cmdty
            return getCommodityInfo(pair.first).mass_per_unit * pair.second;    // mass_per_unit * qty
        });

        return std::accumulate(cargo_mass_view.begin(), cargo_mass_view.end(), 0.0f);
    }
}