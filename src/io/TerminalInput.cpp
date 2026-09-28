#include "TerminalInput.h"
#include "Command.h"
#include "domain/Commodity.h"
#include <format>
#include <iostream>
// UI in terminal for the sake of testing
// TODO: ftxui or Qt-based UI

namespace sm
{

    MenuOption TerminalInput::getMenuOption() const
    {
        std::cout << "  Your choice [n-New Game, q-Quit]: ";
        std::string choice;
        std::cin >> choice;

        if (choice == "n" || choice == "newgame")
            return MenuOption::NewGame;
        return MenuOption::Quit;
    }

    Command TerminalInput::getCommand() const
    {
        std::string prompt = std::format("  Your choice [{}-Travel, {}-Buy, {}-Sell, {}-Quit]: ", 1, 2, 3, "q");
        std::cout << prompt;

        std::string choice;
        std::cin >> choice;

        if (choice == "1" || choice == "travel") {
            return Command::Travel;
        }
        else if (choice == "2" || choice == "buy") {
            return Command::Buy;
        }
        else if (choice == "3" || choice == "sell") {
            return Command::Sell;
        }
        else if (choice == "n" || choice == "newgame") {
            return Command::NewGame;
        }
        else if (choice == "q" || choice == "quit") {
            return Command::Quit;
        }
        else
        {
            std::cout << std::format("  Error: '{}' is an unknown command!\n", choice);
            return getCommand(); // or while()
        }
    }

    int TerminalInput::getSystemId() const
    {
        std::cout << "  Enter Target System ID: ";

        int systemId = 0;
        std::cin >> systemId;

        if (systemId <= 0)
        {
            std::cout << "  [Warning] Invalid system ID, defaulting to 1\n";
            systemId = 1;
        }

        return systemId;
    }

    Commodity TerminalInput::getCommodity() const
    {
        std::cout << std::format("  Enter Commodity Type:\n"
                                 "  [0] Cybernetics\n"
                                 "  [1] Deuterium\n"
                                 "  [2] HydroRations\n"
                                 "  [3] RareOre\n"
                                 "  [4] Stardust\n"
                                 "  Choose commodity (0-4): ");

        int choice = 0;
        std::cin >> choice;

        if (choice < 0 || choice > 4) {
            std::cout << std::format("  [Warning] Invalid choice, defaulting to Cybernetics (0)\n");
            choice = 0;
        }

        return static_cast<Commodity>(choice);
    }

    int TerminalInput::getQuantity() const
    {
        std::cout << "  Enter Quantity: ";

        int quantity = 0;
        std::cin >> quantity;

        if (quantity <= 0)
        {
            std::cout << "  [Warning] Invalid quantity, defaulting to 1\n";
            quantity = 1;
        }

        return quantity;
    }

    ShipType TerminalInput::getShipType() const
    {
        std::cout << std::format("  Available Ship Types:\n"
                                 "  [0] Shuttle\n"
                                 "  [1] Freighter\n"
                                 "  [2] Interceptor\n"
                                 "  Choose ship type (0-2): ");

        int choice = 0;
        std::cin >> choice;

        if (choice < 0 || choice > 2) {
            std::cout << std::format("  [Warning] Invalid choice, defaulting to Shuttle (0)\n");
            choice = 0;
        }

        return static_cast<ShipType>(choice);
    }
}