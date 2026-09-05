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

    int Galaxy::getSystemCount() const
    {
        return static_cast<int>(m_star_sys_list.size());
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

    void Galaxy::addSystem(StarSystem system)
    {
        m_star_sys_list.emplace_back(std::move(system));
    }

    void Galaxy::addEdge(int from_id, int to_id, float dist)
    {
        auto& edges = m_galaxy_adjacency_map[from_id];
        auto exists = std::ranges::find_if(edges,
            [to_id](const Edge& e) { return e.target_system_id == to_id; });

        if(exists == edges.end())
        {
            m_galaxy_adjacency_map[from_id].emplace_back(to_id, dist);
            m_galaxy_adjacency_map[to_id].emplace_back(from_id, dist);
        }
    }

    void Galaxy::setCapitalId(int id)
    {
        m_capital_id = id;
    }
}