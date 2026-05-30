#pragma once

#include "domain/GameStatus.h"
#include "entities/Player.h"
#include "map/Galaxy.h"

namespace sm
{
    class GameState
    {
    public:
        GameState(Galaxy galaxy, Player player, GameStatus game_status);

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
        int m_current_system_id;
        int m_turn;
    };
}
