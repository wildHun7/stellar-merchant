#pragma once

#include "Ship.h"

namespace sm
{
    class Player
    {
    public:
        Player(float ship_limit);

        // Ship
        [[nodiscard]] const Ship& getShip() const;
        [[nodiscard]] Ship& getShip();

        // Credits
        [[nodiscard]] bool spendCredits(float amount);
        [[nodiscard]] float getCredits() const;
        void addCredits(float amount);

    private:
        Ship m_ship;
        float m_credits;
    };
}
