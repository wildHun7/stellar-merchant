#include "RandomMapGenerator.h"
#include <random>
#include <format>
#include <algorithm>

namespace sm
{
    Galaxy RandomMapGenerator::generateGalaxy(int system_count, unsigned int seed) const
    {
        std::mt19937 gen(seed);
        std::uniform_real_distribution<float> pos_dist(0.0f, 1000.0f);

        Galaxy galaxy;

        // generate solar systems
        for(int i = 0; i < system_count; ++i)
        {
            float x = pos_dist(gen);
            float y = pos_dist(gen);

            //TODO: generate planets for each system
            StarSystem system(i, std::format("System_{}", i), Position{x, y}, {});

            galaxy.addSystem(std::move(system));
        }

        // connect systems
        constexpr int K = 4;

        for(int i = 0; i < system_count; ++i)
        {
            std::vector<std::pair<float, int>> distances;

            for(int j = 0; j < system_count; ++j)
            {
                if(j == i) continue;

                const auto& pos_i = galaxy.getSystem(i).getPosition();
                const auto& pos_j = galaxy.getSystem(j).getPosition();

                float dx = pos_i.x - pos_j.x;
                float dy = pos_i.y - pos_j.y;
                float dist = std::sqrt(dx*dx + dy*dy);

                distances.emplace_back(dist, j);
            }

            std::ranges::sort(distances);
            int neighbours = std::min(K, static_cast<int>(distances.size()));

            for (int k = 0; k < neighbours; ++k)
            {
                galaxy.addEdge(i, distances[k].second, distances[k].first); // arg: from_id, to_id, cost
            }
        }

        // set Capital
        Position center{500.0f, 500.0f};
        int capital_id = 0;
        float max_dist = 0.0f;

        for (int i = 0; i < system_count; ++i)
        {
            const auto& pos = galaxy.getSystem(i).getPosition();
            float dx = pos.x - center.x;
            float dy = pos.y - center.y;
            float dist = std::sqrt(dx*dx + dy*dy);

            if (dist > max_dist)
            {
                max_dist = dist;
                capital_id = i;
            }
        }

        galaxy.setCapitalId(capital_id);

        return galaxy;
    }
}