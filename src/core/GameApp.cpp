#include "GameApp.h"
#include "world/Galaxy.h"
#include "world/map/RandomMapGenerator.h"
#include "entities/Player.h"
#include "entities/Ship.h"

namespace sm
{
    GameApp::GameApp(std::unique_ptr<IRenderer> renderer, std::unique_ptr<IInputHandler> input_handler)
    :   m_renderer(std::move(renderer))
    ,   m_input_handler(std::move(input_handler))
    ,   m_menu_session(*m_renderer, *m_input_handler)
    {   }

    void GameApp::run()
    {
        while(true)
        {
            if (m_menu_session.run() == MenuOption::Quit)
                break;

            RandomMapGenerator map_generator;
            Galaxy galaxy = map_generator.generateGalaxy(10, 42); // count, seed
            auto ship_type = m_input_handler->getShipType();
            Player player{Ship(ship_type)}; // most vexing perse

            m_game_session.emplace(std::move(galaxy), std::move(player) ,*m_renderer, *m_input_handler);
            m_game_session->run();
            m_game_session.reset();
        }
    }
}