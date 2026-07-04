#pragma once

#include "IMapGenerator.h"

namespace sm
{
    class RandomMapGenerator : public IMapGenerator
    {
    public:
        ~RandomMapGenerator() = default;

        Galaxy generateGalaxy(int system_count, unsigned int seed) const override;

    private:
        //std::mt19937 m_gen;
    };
}
