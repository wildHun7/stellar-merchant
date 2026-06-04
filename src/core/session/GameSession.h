#pragma once

#include "domain/GameStatus.h"
#include "entities/Player.h"
#include "world/Galaxy.h"
#include "context/IContext.h"
#include "io/IInputHandler.h"
#include "io/IRenderer.h"
#include <memory>

namespace sm
{
    class GameSession
    {
    public:
        explicit GameSession(Galaxy galaxy, Player player, IRenderer& renderer, IInputHandler& handler);

        void run();
        [[nodiscard]] bool isRunning() const;
        void switchContext(std::unique_ptr<IContext> context);

        [[nodiscard]] const Galaxy& getGalaxy() const;
        [[nodiscard]] Galaxy& getGalaxy();

        [[nodiscard]] const Player& getPlayer() const;
        [[nodiscard]] Player& getPlayer();

        [[nodiscard]] GameStatus getGameStatus();
        void setGameStatus(GameStatus game_status);

        [[nodiscard]] int getCurrentSystemId() const;
        void setCurrentSystemId(int id);

        [[nodiscard]] int getTurn() const;
        void nextTurn();

    private:
        Galaxy m_galaxy;
        Player m_player;
        GameStatus m_game_status;
        std::unique_ptr<IContext> m_context;
        IRenderer& m_renderer;
        IInputHandler& m_handler;
        int m_current_system_id;
        int m_turn;
    };
}
