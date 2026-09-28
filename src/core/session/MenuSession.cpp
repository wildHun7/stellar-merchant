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
        MenuOption cmd = m_input_handler.getMenuOption();

        if (cmd == MenuOption::NewGame)
            return MenuOption::NewGame;

        return MenuOption::Quit;
    }
}