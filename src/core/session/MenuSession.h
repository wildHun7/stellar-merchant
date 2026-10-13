#pragma once

#include "io/Command.h"

namespace sm
{

    class MenuSession
    {
    public:
        explicit MenuSession();

        [[nodiscard]] MenuOption run();

    private:

    };

}
