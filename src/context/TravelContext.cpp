#include "TravelContext.h"
#include "CityContext.h"
#include "QuitContext.h"

namespace sm
{
    std::unique_ptr<IContext> TravelContext::update(Player& player, Galaxy& galaxy, int current_system_id)
    {
        m_renderer.renderState(player, galaxy, current_system_id);
        m_renderer.renderAvailableActions(getAvailableActions());
        Command cmd = m_input.getCommand();

        switch(cmd) {
            case Command::Travel:
            {
                int target_system_id = m_input.getSystemId();
                auto result = m_travel_system.travel(player, galaxy, current_system_id, target_system_id);
                m_renderer.renderMessage(result);
                if (result.success)
                    return std::make_unique<CityContext>(galaxy.getSystem(target_system_id).getPlanets()[0], m_renderer, m_input);
                // TODO: planet generator
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

    std::vector<Command> TravelContext::getAvailableActions() const
    {
        return {Command::Travel, Command::Quit};
    }
}