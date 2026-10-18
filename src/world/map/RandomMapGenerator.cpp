#include "RandomMapGenerator.h"
#include "world/Market.h"
#include <random>
#include <format>
#include <algorithm>

namespace sm
{
    Galaxy RandomMapGenerator::generateGalaxy(int system_count, unsigned int seed, IPricingStrategy& pricing) const
    {
        std::mt19937 gen(seed);

        //std::uniform_real_distribution<float> pos_dist(0.0f, 1000.0f);

        constexpr float MAP_WIDTH  = 60.0f;
        constexpr float MAP_HEIGHT = 10.0f;
        std::uniform_real_distribution<float> pos_x(0.0f, MAP_WIDTH);
        std::uniform_real_distribution<float> pos_y(0.0f, MAP_HEIGHT);

        Galaxy galaxy;

        //  1. generate solar systems
        for(int i = 0; i < system_count; ++i)
        {
            // float x = pos_dist(gen);
            // float y = pos_dist(gen);

            float x = pos_x(gen);
            float y = pos_y(gen);

            StarSystem system(i, std::format("System_{}", i), Position{x, y}, {}); // TODO: generate planets for each system
            galaxy.addSystem(std::move(system));
        }

        // 2. connect systems
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
                galaxy.addEdge(i, distances[k].second, distances[k].first); // arg: from_id, to_id, dist
            }
        }

        // 3. set capital
        Position center{30.0f, 5.0f};
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

        // 4. generate planets
        std::uniform_int_distribution<int> planet_count_range(1, 3); // up to 3 planets in the system
        std::uniform_int_distribution<int> planet_type_range(0, 4);  // 5 planet type

        for (int i = 0; i < system_count; ++i)
        {
            int count = planet_count_range(gen);
            auto& system = galaxy.getSystem(i);

            for (int p = 0; p < count; ++p)
            {
                PlanetType type = static_cast<PlanetType>(planet_type_range(gen));
                std::string name = std::format("Planet_{}-{}", i, p);
                float dist_from_capital = galaxy.getSystem(galaxy.getCapitalID()).getPosition().x; // TODO: real distance

                Market market(type, dist_from_capital, pricing, seed);
                system.getPlanets().emplace_back(name, type, std::move(market));
            }
        }

        return galaxy;
    }
}