#pragma once

#include "domain/Commodity.h"
#include "Cargo.h"

namespace sm
{
    class Ship
    {
    public:
        explicit Ship(float mass_limit);

        // Commodity
        [[nodiscard]] bool addCommodity(Commodity cmdty_type, int quantity);
        [[nodiscard]] bool removeCommodity(Commodity cmdty_type, int quantity);

        // Fuel
        [[nodiscard]] int getFuelAmount() const;
        [[nodiscard]] bool consumeFuel(float amount);

        // Mass
        [[nodiscard]] float getAvailableMass() const;

    private:
        Cargo m_cargo;
        float m_cargo_mass_limit;
    };
}
