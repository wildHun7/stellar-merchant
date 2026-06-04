#pragma once

#include "session/GameSession.h"
#include "session/MenuSession.h"
#include "io/IInputHandler.h"
#include "io/IRenderer.h"
#include <memory>
#include <optional>

namespace sm
{
    class GameLoop
    {
    public:
        explicit GameLoop(std::unique_ptr<IRenderer> renderer, std::unique_ptr<IInputHandler> input);

        void run();

    private:
        MenuSession m_menu_session;
        std::optional<GameSession> m_game_session;
        // std::optional<WorldSession> m_world_session; TODO

        std::unique_ptr<IRenderer> m_renderer;
        std::unique_ptr<IInputHandler> m_input_handler;
    };
}
