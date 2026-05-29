#pragma once

#include "Cargo.h"
#include "domain/Commodity.h"

namespace sm
{
    class Ship
    {
    public:
        Ship(float mass_limit);

        // Commodity
        [[nodiscard]] bool addCommodity(Commodity type, int quantity);
        [[nodiscard]] bool removeCommodity(Commodity type, int quantity);
        [[nodiscard]] float getAvailableMass() const;

        // Fuel
        [[nodiscard]] int getFuelAmount() const;
        [[nodiscard]] bool consumeFuel(float amount);

    private:
        Cargo m_cargo;
        float m_cargo_mass_limit;
    };
}
