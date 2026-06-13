#include "Planet.h"

namespace sm
{
    Planet::Planet(std::string_view planet_name, PlanetType planet_type, Market planet_market)
    : m_planet_name(planet_name)
    , m_planet_type(planet_type)
    , m_planet_market(std::move(planet_market))
    {}

    const std::string& Planet::getName() const
    {
        return m_planet_name;
    }

    PlanetType Planet::getType() const
    {
        return m_planet_type;
    }
    Market& Planet::getMarket()
    {
        return m_planet_market;
    }
    const Market& Planet::getMarket() const
    {
        return m_planet_market;
    }
}