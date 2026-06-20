#include "Galaxy.h"
#include <algorithm>
#include <stdexcept>
#include <format>

namespace sm
{
    StarSystem& Galaxy::getSystem(int id)
    {
        auto it = std::ranges::find_if(m_star_sys_list, [id](const StarSystem& sys)
            {return sys.getId() == id;});

        if(it == m_star_sys_list.end())
            throw std::out_of_range(std::format("StarSystem with id {} not found", id));

        return *it;
    }

    const StarSystem& Galaxy::getSystem(int id) const
    {
        auto it = std::ranges::find_if(m_star_sys_list, [id](const StarSystem& sys)
            {return sys.getId() == id;});

        if(it == m_star_sys_list.end())
            throw std::out_of_range(std::format("StarSystem with id {} not found", id));

        return *it;
    }

    const std::vector<Edge>& Galaxy::getNeighbours(int sys_id) const
    {
        auto it = m_galaxy_adjacency_map.find(sys_id);
        if(it == m_galaxy_adjacency_map.end())
            throw std::out_of_range(std::format("No edges for system {}", sys_id));
        return it->second; // second == Edge
    }

    int Galaxy::getCapitalID() const
    {
        return m_capital_id;
    }
}