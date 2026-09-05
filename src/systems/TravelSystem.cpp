#include "TravelSystem.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <format>
//#include <limits>

namespace sm
{
    std::vector<int> TravelSystem::getRoute(const Galaxy& galaxy, int from_id, int to_id) const
    {
        std::unordered_map<int, int> previous;
        std::unordered_map<int, float> dist;

        for(int i = 0; i < galaxy.getSystemCount(); ++i)
            dist[i] = std::numeric_limits<float>::infinity();

        dist[from_id] = 0.0f;

        std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
        pq.push({from_id, 0.0f});

        while(!pq.empty())
        {
            auto [curr_sys_id, current_dist] = pq.top();
            pq.pop();

            if(curr_sys_id == to_id)
            {
                std::vector<int> route;
                int current = to_id;
                while(current != from_id)
                {
                    route.push_back(current);
                    current = previous[current];
                }
                route.push_back(from_id);
                std::ranges::reverse(route);
                return route;
            }

            if(current_dist > dist[curr_sys_id])
                continue;

            for(auto& neighbour_edge: galaxy.getNeighbours(curr_sys_id))
            {
                float new_dist = dist[curr_sys_id] + neighbour_edge.distance;
                if(new_dist < dist[neighbour_edge.target_system_id])
                {
                    dist[neighbour_edge.target_system_id] = new_dist;
                    previous[neighbour_edge.target_system_id] = curr_sys_id;
                    pq.push({neighbour_edge.target_system_id, new_dist});
                }
            }
        }
        return {};
    }

    float TravelSystem::getTravelCost(const Galaxy& galaxy, const Ship& ship, int from_id, int to_id) const
    {
        std::vector<int> route = getRoute(galaxy, from_id, to_id);

        if(route.size() < 2)
            return 0.0f;

        float total_distance = 0.0f;

        for(int i = 0; i < route.size() - 1; ++i)
        {
            // current_id = route[i];
            int next_id = route[i+1];

            const auto& neighbours = galaxy.getNeighbours(route[i]);

            auto it = std::ranges::find_if(neighbours, [next_id](const Edge& edge){
                return edge.target_system_id == next_id;
            });

            if(it != neighbours.end())
                total_distance += it->distance;
        }

        return total_distance * ship.getFuelConsumption();
    }

    Result TravelSystem::travel(Player& player, const Galaxy& galaxy, int from_id, int to_id)
    {
        float travel_cost = getTravelCost(galaxy, player.getShip(), from_id, to_id);

        if(travel_cost > player.getShip().getFuelAmount())
            return {false, std::format("Not enough Deuterium. Need {:.1f}, have {}", travel_cost, player.getShip().getFuelAmount())};

        if (!player.getShip().consumeFuel(static_cast<int>(travel_cost)))
            return {false, "Failed to consume fuel"};

        return {true, std::format("Travelled to {}", galaxy.getSystem(to_id).getName())};
    }
}