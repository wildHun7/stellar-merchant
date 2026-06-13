#include "StarSystem.h"

namespace sm
{
    StarSystem::StarSystem(int id, std::string_view sys_name, Position xy, std::vector<Planet> planet_list)
    : m_id(id)
    , m_system_name(sys_name)
    , m_xy(std::move(xy))
    , m_planet_list(std::move(planet_list))
    {}

    int StarSystem::getId() const
    {
        return m_id;
    }

    const std::string& StarSystem::getName() const
    {
        return m_system_name;
    }

    const Position& StarSystem::getPosition() const
    {
        return m_xy;
    }

    std::vector<Planet>& StarSystem::getPlanets()
    {
        return m_planet_list;
    }

    const std::vector<Planet>& StarSystem::getPlanets() const
    {
        return m_planet_list;
    }
}