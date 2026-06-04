#pragma once

#include "io/IInputHandler.h"
#include "io/IRenderer.h"

namespace sm
{
    enum class MenuOption
    {
        NewGame,
        Quit
    };

    class MenuSession
    {
    public:
        explicit MenuSession(IRenderer& renderer, IInputHandler& handler);

        [[nodiscard]] MenuOption run();

    };

}
