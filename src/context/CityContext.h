#pragma once

#include "IContext.h"
#include "systems/TradeSystem.h"
#include "world/Planet.h"

namespace sm
{
    class CityContext : public IContext
    {
    public:
        explicit CityContext(Planet& planet);
        ~CityContext() = default;

    private:
        TradeSystem m_trade_system;
        Planet& m_planet;
    };
}
