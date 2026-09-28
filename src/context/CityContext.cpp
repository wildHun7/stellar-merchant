#include "CityContext.h"
#include "QuitContext.h"
#include "TravelContext.h"
#include "io/Command.h"
#include "domain/Commodity.h"

namespace sm
{
    CityContext::CityContext(Planet& planet, IRenderer& renderer, IInputHandler& input)
    :   m_planet(planet)
    ,   m_renderer(renderer)
    ,   m_input(input)
    {   }

    std::unique_ptr<IContext> CityContext::update(Player& player, Galaxy& galaxy, int current_system_id)
    {
        m_renderer.renderState(player, galaxy, current_system_id);
        m_renderer.renderAvailableActions(getAvailableActions());
        Command cmd = m_input.getCommand();

        switch(cmd) {
            case Command::Sell:
            {
                Commodity commodity = m_input.getCommodity();
                int quantity = m_input.getQuantity();
                auto result = m_trade_system.sellCommodity(player, m_planet, commodity, quantity);
                m_renderer.renderMessage(result);
                break;
            }

            case Command::Buy:
            {
                Commodity commodity = m_input.getCommodity();
                int quantity = m_input.getQuantity();
                auto result = m_trade_system.buyCommodity(player, m_planet, commodity, quantity);
                m_renderer.renderMessage(result);
                break;
            }

            case Command::Travel:
            {
                return std::make_unique<TravelContext>(m_renderer, m_input);
                break;
            }

            case Command::Quit:
            {
                return std::make_unique<QuitContext>();
                break;
            }

            default:
            {
                m_renderer.renderMessage({false, "Unknown command"});
                break;
            }
        }
        return nullptr;
    }

    std::vector<Command> CityContext::getAvailableActions() const
    {
        return {Command::Sell, Command::Buy, Command::Travel, Command::Quit};
    }
}