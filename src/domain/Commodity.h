#pragma once

// #include <format>
// #include <stdexcept>
#include <string_view>
#include <array>

namespace sm
{
    enum class Commodity
    {
        Cybernetics,    // technology
        Deuterium,      // fuel
        HydroRations,   // food
        RareOre,        // minerals
        Stardust,       // luxury
    };

    struct CommodityInfo
    {
        Commodity type;
        std::string_view name;
        float mass_per_unit;
        int base_price;
    };

    inline constexpr std::array<CommodityInfo, 5> kCommodities
    {{
        { Commodity::Cybernetics,  "Cybernetics",   2.0f,  20 },
        { Commodity::Deuterium,    "Deuterium",     1.5f,  50 },
        { Commodity::HydroRations, "Hydro-Rations", 1.0f,  20 },
        { Commodity::RareOre,      "Rare Ore",      4.0f, 200 },
        { Commodity::Stardust,     "Stardust",      0.5f, 500 },
    }};

    constexpr const CommodityInfo& getCommodityInfo(Commodity type)
    {
        for(const auto& info : kCommodities){
            if(info.type == type)
                return info;
        }

    return kCommodities[0]; // nigdy nie dojdziemy tutaj

    // option 2, but w/o constexpr
    // throw std::invalid_argument(
    //     std::format("Unknown CommodityType ID: {}", static_cast<int>(type))
    }
} // namespace sm
