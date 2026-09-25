#include "GameSession.h"
#include "context/TravelContext.h"
//#include "context/CityContext.h"

namespace sm
{
    GameSession::GameSession(Galaxy galaxy, Player player, IRenderer& renderer, IInputHandler& input_handler)
    :   m_galaxy(std::move(galaxy))
    ,   m_player(std::move(player))
    ,   m_renderer(renderer)
    ,   m_input_handler(input_handler)
    ,   m_current_system_id(0)
    ,   m_turn(0)
    ,   m_game_status(GameStatus::Playing)
    ,   m_context(std::make_unique<TravelContext>(renderer, input_handler)) // TODO planet generator & takeoff from planet
    {   }

    void GameSession::run()
    {
        while(isRunning())
        {
            auto next_context = m_context->update(m_player, m_galaxy, m_current_system_id);

            if(next_context == nullptr)
                continue;
            else if(next_context->wantsToQuit())
                m_game_status = GameStatus::Quit;
            else
                m_context = std::move(next_context);

            nextTurn();
        }
    }

    bool GameSession::isRunning() const
    {
        return m_game_status == GameStatus::Playing; // "==" to compare
    }

    void GameSession::switchContext(std::unique_ptr<IContext> context)
    {
        m_context = std::move(context);
    }

    const Galaxy& GameSession::getGalaxy() const
    {
        return m_galaxy;
    }

    Galaxy& GameSession::getGalaxy()
    {
        return m_galaxy;
    }

    const Player& GameSession::getPlayer() const
    {
        return m_player;
    }

    Player& GameSession::getPlayer()
    {
        return m_player;
    }

    GameStatus GameSession::getGameStatus() const
    {
        return m_game_status;
    }

    void GameSession::setGameStatus(GameStatus game_status)
    {
        m_game_status = game_status;
    }

    int GameSession::getCurrentSystemId() const
    {
        return m_current_system_id;
    }

    void GameSession::setCurrentSystemId(int id)
    {
        m_current_system_id = id;
    }

    int GameSession::getTurn() const
    {
        return m_turn;
    }

    void GameSession::nextTurn()
    {
        ++m_turn;
    }

}