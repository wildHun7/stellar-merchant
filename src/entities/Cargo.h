#pragma once

#include "domain/Commodity.h"
#include <unordered_map>

namespace sm
{
    class Cargo
    {
    public:
        Cargo() = default;

        // Commodity
        [[nodiscard]] const std::unordered_map<Commodity, int>& getItems() const { return m_stored_cargo; }
        [[nodiscard]] bool addCommodity(Commodity type, int quantity);
        [[nodiscard]] bool removeCommodity(Commodity type, int quantity);
        [[nodiscard]] int getQuantity(Commodity type) const;

        // Mass
        [[nodiscard]] float getCurrentMass() const;

    private:
        std::unordered_map<Commodity, int> m_stored_cargo;
    };
}
