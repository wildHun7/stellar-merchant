#include <QDebug>
#include "GameSession.h"
#include "context/TravelContext.h"
//#include "context/CityContext.h"

namespace sm
{
    GameSession::GameSession(Player player, Galaxy galaxy, QObject* parent)
    :   m_galaxy(std::move(galaxy))
    ,   m_player(std::move(player))
    ,   m_current_system_id(0)
    {
        [[maybe_unused]] bool fueled = m_player.getShip().addCommodity(Commodity::Deuterium, 70);
        qDebug() << "Calling switchContext...";
        switchContext(std::make_unique<TravelContext>());
        qDebug() << "switchContext done!";
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
                //switchContext(std::make_unique<CityContext>());
                break;
            default:
                break;
        }
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
                this, &GameSession::onContextChangeRequested);
        connect(m_context.get(), &IContext::actionCompleted,
                this, &GameSession::onActionCompleted);
        connect(m_context.get(), &IContext::stateChanged,
                this, &GameSession::onStateChanged);
    }
}