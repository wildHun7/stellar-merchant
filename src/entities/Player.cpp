#include "Player.h"

namespace sm
{
    Player::Player(Ship ship) : m_ship(std::move(ship))
    {}

    // Ship

    const Ship& Player::getShip() const
    {
        return m_ship;
    }

    Ship& Player::getShip()
    {
        return m_ship;
    }

    // Credits

    bool Player::spendCredits(float amount)
    {
        if(m_credits < amount)
            return false;

        m_credits -= amount;

        return true;
    }

    float Player::getCredits() const
    {
        return m_credits;
    }

    void Player::addCredits(float amount)
    {
        m_credits += amount;
    }

}