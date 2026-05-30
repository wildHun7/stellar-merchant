#pragma once

#include "GameState.h"
#include "systems/TradeSystem.h"
#include "systems/TravelSystem.h"
#include "io/IInputHandler.h"
#include "io/IRenderer.h"
#include <memory>

namespace sm
{
    class GameLoop
    {
    public:
        explicit GameLoop(GameState game_state, TradeSystem trade_sys, TravelSystem travel_sys);

        void run();

    private:
        GameState m_game_state;
        std::unique_ptr<IRenderer> m_renderer;
        std::unique_ptr<IInputHandler> m_input_handler;
        TradeSystem m_trade_system;
        TravelSystem m_travel_system;
    };
}
