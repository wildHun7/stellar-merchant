#include "MenuSession.h"
#include "io/Command.h"

namespace sm
{
    MenuSession::MenuSession(IRenderer& renderer, IInputHandler& input_handler)
    :   m_renderer(renderer)
    ,   m_input_handler(input_handler)
    {   }

    MenuOption MenuSession::run()
    {
        m_renderer.renderMenu();
        Command cmd = m_input_handler.getCommand();

        if (cmd == Command::NewGame)
            return MenuOption::NewGame;

        return MenuOption::Quit;
    }
}