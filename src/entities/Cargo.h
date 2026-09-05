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
        [[nodiscard]] int getQuantity(Commodity cmdty_type) const;
        [[nodiscard]] bool addCommodity(Commodity cmdty_type, int quantity);    //bool + nodiscard for validation
        [[nodiscard]] bool removeCommodity(Commodity cmdty_type, int quantity);

        // Mass
        [[nodiscard]] float getCurrentMass() const;

    private:
        std::unordered_map<Commodity, int> m_stored_cargo;
    };
}
