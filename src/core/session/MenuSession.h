#pragma once

#include "io/IInputHandler.h"
#include "io/IRenderer.h"
#include "io/Command.h"

namespace sm
{

    class MenuSession
    {
    public:
        explicit MenuSession(IRenderer& renderer, IInputHandler& handler);

        [[nodiscard]] MenuOption run();

    private:
        IRenderer& m_renderer;
        IInputHandler& m_input_handler;

    };

}
