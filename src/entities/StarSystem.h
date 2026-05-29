#pragma once

#include "domain/Position.h"
#include "Planet.h"
#include <string>
#include <string_view>
#include <vector>

namespace sm
{
    class StarSystem
    {
    public:
        explicit StarSystem(int ID, std::string_view sys_name, Position xy, std::vector<Planet> planet_list);

        [[nodiscard]] int getId() const;
        [[nodiscard]] const std::string& getName() const;
        [[nodiscard]] const Position& getPosition() const;
        [[nodiscard]] std::vector<Planet>& getPlanets();
        [[nodiscard]] const std::vector<Planet>& getPlanets() const;

    private:
        int m_id;
        std::string m_system_name;
        Position m_xy;
        std::vector<Planet> m_planet_list;
    };
}
