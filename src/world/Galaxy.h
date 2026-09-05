#pragma once

#include "StarSystem.h"
#include "map/Edge.h"
#include <vector>
#include <unordered_map>

namespace sm
{
    class Galaxy
    {
    public:
        Galaxy() = default;

        [[nodiscard]] StarSystem& getSystem(int id);
        [[nodiscard]] const StarSystem& getSystem(int id) const;
        [[nodiscard]] int getSystemCount() const;
        [[nodiscard]] const std::vector<Edge>& getNeighbours(int sys_id) const;
        [[nodiscard]] int getCapitalID() const;

        void addSystem(StarSystem system);
        void addEdge(int from_id, int to_id, float cost);
        void setCapitalId(int id);

    private:
        std::vector<StarSystem> m_star_sys_list;
        std::unordered_map<int, std::vector<Edge>> m_galaxy_adjacency_map;
        int m_capital_id;
    };
}
