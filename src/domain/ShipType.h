#pragma once

#include <string_view>
#include <array>

namespace sm
{
    enum class ShipType
    {
    Shuttle,
    Freighter,
    Interceptor
    };

    struct ShipInfo
    {
        ShipType type;
        std::string_view name;
        float cargo_capacity;
        float fuel_consumption;
    };

    inline constexpr std::array<ShipInfo, 3> kShips
    {{
        { ShipType::Shuttle,     "Shuttle",     50.0f,  1.0f },
        { ShipType::Freighter,   "Freighter",  150.0f,  2.0f },
        { ShipType::Interceptor, "Interceptor", 80.0f,  0.5f },
    }};

    constexpr const ShipInfo& getShipInfo(ShipType type)
    {
        for (const auto& info : kShips)
        {
            if (info.type == type)
                return info;
        }
        return kShips[0]; // unreachable
    }
}