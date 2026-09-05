#pragma once

#include "domain/Commodity.h"
#include "domain/ShipType.h"
#include "Cargo.h"

namespace sm
{
    class Ship
    {
    public:
        explicit Ship(ShipType ship_type);

        // Commodity
        [[nodiscard]] bool addCommodity(Commodity cmdty_type, int quantity);
        [[nodiscard]] bool removeCommodity(Commodity cmdty_type, int quantity);

        // Fuel
        [[nodiscard]] int getFuelAmount() const;
        [[nodiscard]] bool consumeFuel(int amount);
        [[nodiscard]] float getFuelConsumption() const;

        // Mass
        [[nodiscard]] float getAvailableMass() const;
        [[nodiscard]] float getCurrentMass() const;
        [[nodiscard]] float getMaxMass() const;

    private:
        Cargo m_cargo;
        ShipType m_ship_type;
        float m_cargo_capacity;
        float m_fuel_consumption;
    };
}
