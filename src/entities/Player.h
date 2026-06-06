#pragma once

#include "Ship.h"

namespace sm
{
    class Player
    {
    public:
        explicit Player(Ship ship);

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
