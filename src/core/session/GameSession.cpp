#include <QDebug>
#include "GameSession.h"
#include "context/TravelContext.h"
#include "context/CityContext.h"
#include "world/map/RandomMapGenerator.h"

namespace sm
{
    GameSession::GameSession(ShipType ship_type, QObject* parent)
    :   QObject(parent)
    ,   m_pricing()
    ,   m_player{Ship(ship_type)}
    ,   m_galaxy(RandomMapGenerator{}.generateGalaxy(10, 42, m_pricing))
    {
        [[maybe_unused]] bool fueled = m_player.getShip().addCommodity(Commodity::Deuterium, 50);
        switchContext(std::make_unique<CityContext>(getCurrentPlanet()));
    }

    Planet& GameSession::getCurrentPlanet()
    {
        return m_galaxy.getSystem(m_current_system_id).getPlanets()[m_current_planet_id];
    }

    const Planet& GameSession::getCurrentPlanet() const
    {
        return m_galaxy.getSystem(m_current_system_id).getPlanets()[m_current_planet_id];
    }

    void GameSession::initialize()
    {
        emit stateChanged(m_player, m_galaxy, m_current_system_id);
    }

    void GameSession::onBuyRequested(Commodity commodity, int quantity)
    {
        m_context->onBuyRequested(m_player, getCurrentPlanet(), commodity, quantity);
    }

    void GameSession::onSellRequested(Commodity commodity, int quantity)
    {
        m_context->onSellRequested(m_player, getCurrentPlanet(), commodity, quantity);
    }

    void GameSession::onTravelRequested(int target_system_id)
    {
        m_context->onTravelRequested(m_player, m_galaxy, m_current_system_id, target_system_id);
    }

    void GameSession::onDepartureRequested(int target_system_id)
    {
        switchContext(std::make_unique<TravelContext>(target_system_id));
    }

    void GameSession::onSystemChanged(int system_id)
    {
        m_current_system_id = system_id;
        m_current_planet_id = 0;
    }

    void GameSession::onContextChangeRequested(ContextType type)
    {
        switch (type)
        {
        case ContextType::City:
            switchContext(std::make_unique<CityContext>(getCurrentPlanet()));
            break;
        default:
            break;
        }
        emit stateChanged(m_player, m_galaxy, m_current_system_id);
    }

    void GameSession::onActionCompleted(const Result& result)
    {
        emit messageReceived(QString::fromStdString(result.message));
    }

    void GameSession::onStateChanged()
    {
        emit stateChanged(m_player, m_galaxy, m_current_system_id);
    }

    void GameSession::switchContext(std::unique_ptr<IContext> context)
    {
        m_context = std::move(context);

        connect(m_context.get(), &IContext::contextChangeRequested,
                this, &GameSession::onContextChangeRequested, Qt::QueuedConnection);
        connect(m_context.get(), &IContext::departureRequested,
                this, &GameSession::onDepartureRequested, Qt::QueuedConnection);

        connect(m_context.get(), &IContext::systemChanged,
                this, &GameSession::onSystemChanged);
        connect(m_context.get(), &IContext::actionCompleted,
                this, &GameSession::onActionCompleted);
        connect(m_context.get(), &IContext::stateChanged,
                this, &GameSession::onStateChanged);

        m_context->onEnter(m_player, m_galaxy, m_current_system_id);
    }
}