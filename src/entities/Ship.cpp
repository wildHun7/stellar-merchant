#include <QDebug>
#include "Ship.h"

namespace sm
{
    Ship::Ship(ShipType type)
        : m_ship_type(type)
        , m_cargo_capacity(getShipInfo(type).cargo_capacity)
        , m_fuel_consumption(getShipInfo(type).fuel_consumption)
    {
        qDebug() << "Ship created, type:" << static_cast<int>(type)
        << "capacity:" << m_cargo_capacity;
    }

    // Commodity

    bool Ship::addCommodity(Commodity cmdty_type, int quantity)
    {
        qDebug() << "cargo capacity:" << m_cargo_capacity;
        qDebug() << "current mass:" << m_cargo.getCurrentMass();

        if (quantity <= 0)
        {
            qDebug() << "quantity <= 0";
            return false;
        }

        float new_mass = m_cargo.getCurrentMass() + getCommodityInfo(cmdty_type).mass_per_unit * quantity;
        qDebug() << "new_mass:" << new_mass << "capacity:" << m_cargo_capacity;
        if(new_mass > m_cargo_capacity)
        {
            qDebug() << "over capacity!";
            return false;
        }
        return m_cargo.addCommodity(cmdty_type, quantity);
    }

    bool Ship::removeCommodity(Commodity cmdty_type, int quantity)
    {
        return m_cargo.removeCommodity(cmdty_type, quantity);
    }

    int Ship::getQuantity(Commodity cmdty_type) const
    {
        return m_cargo.getQuantity(cmdty_type);
    }

    // Fuel

    int Ship::getFuelAmount() const
    {
        return m_cargo.getQuantity(Commodity::Deuterium);
    }

    bool Ship::consumeFuel(int amount)
    {
        return m_cargo.removeCommodity(Commodity::Deuterium, amount);
    }

    float Ship::getFuelConsumption() const
    {
        return m_fuel_consumption;
    }

    // Mass

    float Ship::getAvailableMass() const
    {
        return m_cargo_capacity - m_cargo.getCurrentMass();
    }
    float Ship::getCurrentMass() const
    {
        return m_cargo.getCurrentMass();
    }
    float Ship::getMaxMass() const
    {
        return m_cargo_capacity;
    }

}
