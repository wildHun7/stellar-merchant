#include "StandardPricing.h"

namespace // anonimowy namespace — widoczny tylko w tym pliku
{
inline constexpr std::array<std::array<float, 5>, 5> kPlanetMultipliers
    {{
        // Hydro  Deut   Cyber  Ore    Dust
        { 0.5f,  1.0f,  1.5f,  1.5f,  1.2f }, // Agricultural
        { 1.5f,  1.5f,  1.0f,  1.0f,  0.3f }, // Capital
        { 1.2f,  0.5f,  1.2f,  1.0f,  1.3f }, // Industrial
        { 1.3f,  1.0f,  1.2f,  0.5f,  1.2f }, // Mining
        { 1.5f,  1.2f,  0.5f,  1.2f,  1.0f }, // Technological

    }};
}

namespace sm
{
    int StandardPricing::calculatePrice(Commodity type, PlanetType planet, float dist) const
    {
        const auto& info = getCommodityInfo(type);
        float price = info.base_price;
        float multiplier = kPlanetMultipliers[static_cast<int>(planet)][static_cast<int>(type)]; // planet type multiplier
        price *= multiplier;
        price *= (1.0f + dist / 1000.0f);     // distance increases price // TODO: normalize by actual max distance
        return static_cast<int>(price);
    }
}