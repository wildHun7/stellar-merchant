#pragma once

#include "domain/PlanetType.h"
#include "Market.h"
#include <string>
#include <string_view>

namespace sm
{
    class Planet
    {
    public:
        explicit Planet(std::string_view planet_name, PlanetType planet_type, Market planet_market);

        [[nodiscard]] const std::string& getName() const;
        [[nodiscard]] PlanetType getType() const;
        [[nodiscard]] Market& getMarket();
        [[nodiscard]] const Market& getMarket() const;

    private:
        std::string m_planet_name;
        PlanetType m_planet_type;
        Market m_planet_market;

    };
}
