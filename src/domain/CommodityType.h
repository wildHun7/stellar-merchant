#pragma once

// #include <format>
// #include <stdexcept>
#include <string_view>
#include <array>

enum class CommodityType
{
    Cybernetics,    // technology
    Deuterium,      // fuel
    HydroRations,   // food
    RareOre,        // minerals
    Stardust,       // leuury
};

struct CommodityInfo
{
    CommodityType type;
    std::string_view name;
    float mass_per_unit;
    int base_price;
};

inline constexpr std::array<CommodityInfo, 5> kCommodities
{{
    { CommodityType::Cybernetics,  "Cybernetics",   2.0f,  20 },
    { CommodityType::Deuterium,    "Deuterium",     1.5f,  50 },
    { CommodityType::HydroRations, "Hydro-Rations", 1.0f,  20 },
    { CommodityType::RareOre,      "Rare Ore",      4.0f, 200 },
    { CommodityType::Stardust,     "Stardust",      0.5f, 500 },
}};

constexpr const CommodityInfo& getCommodityInfo(CommodityType type)
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
