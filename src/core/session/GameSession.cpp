#include <QDebug>
#include "GameSession.h"
#include "context/TravelContext.h"
#include "context/CityContext.h"
#include "world/map/RandomMapGenerator.h"

namespace sm
{
    GameSession::GameSession(QObject* parent)
    :   QObject(parent)
    ,   m_pricing()
    ,   m_player{Ship(ShipType::Shuttle)} // TODO: ship type selection
    ,   m_galaxy(RandomMapGenerator{}.generateGalaxy(10, 42, m_pricing))
    ,   m_current_system_id(0)
    {
        qDebug() << "GameSession body start";
        qDebug() << "player credits:" << m_player.getCredits();
        qDebug() << "ship capacity:" << m_player.getShip().getMaxMass();
        [[maybe_unused]] bool fueled = m_player.getShip().addCommodity(Commodity::Deuterium, 50);
        qDebug() << "fueled:" << fueled;
        qDebug() << "fuel amount:" << m_player.getShip().getFuelAmount();
        qDebug() << "Calling switchContext...";
        switchContext(std::make_unique<TravelContext>());
        qDebug() << "switchContext done!";
    }

    Planet& GameSession::getCurrentPlanet()
    {
        qDebug() << "System planets count:" << m_galaxy.getSystem(m_current_system_id).getPlanets().size();
        return m_galaxy.getSystem(m_current_system_id).getPlanets()[m_current_planet_id];
    }

    const Planet& GameSession::getCurrentPlanet() const
    {
        qDebug() << "System planets count:" << m_galaxy.getSystem(m_current_system_id).getPlanets().size();
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

    void GameSession::onContextChangeRequested(ContextType context_type)
    {
        switch(context_type)
        {
            case ContextType::Travel:
                switchContext(std::make_unique<TravelContext>());
                break;
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
        qDebug() << "GameSession::onStateChanged called!";
        emit stateChanged(m_player, m_galaxy, m_current_system_id);
    }

    void GameSession::switchContext(std::unique_ptr<IContext> context)
    {
        m_context = std::move(context);

        connect(m_context.get(), &IContext::contextChangeRequested,
                this, &GameSession::onContextChangeRequested);
        connect(m_context.get(), &IContext::actionCompleted,
                this, &GameSession::onActionCompleted);
        connect(m_context.get(), &IContext::stateChanged,
                this, &GameSession::onStateChanged);
    }
}