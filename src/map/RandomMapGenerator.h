#pragma once

#include "IMapGenerator.h"
//#include <random>

namespace sm
{
    class RandomMapGenerator : public IMapGenerator
    {
    public:

        Galaxy generateGalaxy(int system_count, unsigned int seed) const override;

    private:
        //std::mt19937 m_gen;
    };
}
