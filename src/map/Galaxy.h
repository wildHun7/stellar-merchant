#pragma once

#include "entities/StarSystem.h"
#include "Edge.h"
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
        [[nodiscard]] const std::vector<Edge>& getNeighbours(int sys_id) const;
        [[nodiscard]] int getCapitalID() const;

    private:
        std::vector<StarSystem> m_star_sys_list;
        std::unordered_map<int, std::vector<Edge>> m_adjacency_map;
    };
}
