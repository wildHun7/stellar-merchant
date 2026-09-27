#include "TerminalRenderer.h"
#include "world/Market.h"
#include <iostream>
#include <format>
#include <algorithm>
#include <array>

namespace sm
{
    void TerminalRenderer::renderState(const Player& player, const Galaxy& galaxy, int current_system_id) const
    {
        // Player Stats
        std::cout << std::format(
            "STELLAR MERCHANT - \n" // TODO Turn {}
            "═══════════════════════════════════\n"
            "  Current System: {}\n"
            "  Credits:        {} CR\n"
            "  Fuel:           {} units (Deuterium)\n"
            "  Cargo:\n",
            galaxy.getSystem(current_system_id).getName(), player.getCredits(), player.getShip().getFuelAmount()
            );

        bool cargo_empty = true;

        std::ranges::for_each(kCommodities, [&](const CommodityInfo& info) {
            int qty = player.getShip().getQuantity(info.type); //

            if (qty > 0) {
                std::cout << std::format("    - {:<12}: {} units\n", info.name, qty);
                cargo_empty = false;
            }
        });

        if (cargo_empty) {
            std::cout << "    - [Empty]\n";
        }

        std::cout << std::format(
            "  Cargo mass:     {:.1f} / {:.1f}\n"
            "═══════════════════════════════════\n",
            player.getShip().getCurrentMass(), player.getShip().getMaxMass()
            );


        // Render Galaxy 2D Map

        std::cout << "  GALAXY MAP\n"
                  << "───────────────────────────────────\n";

        constexpr int MAP_HEIGHT = 10;
        constexpr int MAP_WIDTH  = 60;

        std::array<std::string, MAP_HEIGHT> map_buffer;
        map_buffer.fill(std::string(MAP_WIDTH, '.'));

        // Render Star Systems
        for (const auto& system : galaxy.getStarSystems())
        {
            int col = static_cast<int>(system.getPosition().x);
            int row = static_cast<int>(system.getPosition().y);
            map_buffer[row][col] = '*';
        }

        // Render Player Position
        const auto& current = galaxy.getSystem(current_system_id);
        int curr_col = static_cast<int>(current.getPosition().x);
        int curr_row = static_cast<int>(current.getPosition().y);
        map_buffer[curr_row][curr_col] = '@';

        for (const auto& line : map_buffer)
            std::cout << "  " << line << '\n';

        std::cout << "═══════════════════════════════════\n";
    }

    void TerminalRenderer::renderMarket(const Market& market) const
    {
        std::cout << "═══════════════════════════════════\n"
              << "  LOCAL PLANETARY MARKET           \n"
              << "═══════════════════════════════════\n"
              << std::format("  {:<15} | {:>10}\n", "Commodity", "Price (CR)")
              << "───────────────────────────────────\n";

        std::ranges::for_each(kCommodities, [&](const CommodityInfo& info) {
            int price = market.getPrice(info.type);

        std::cout << std::format("  {:<15} | {:>10} CR\n", info.name, price);
        });

    std::cout << "═══════════════════════════════════\n";
    }

    void TerminalRenderer::renderMessage(const Result& result) const
    {
        std::cout << std::format("  [{}] {}\n", result.success ? "OK" : "ERROR", result.message);
    }

    void TerminalRenderer::renderMenu() const
    {
        std::cout << "\033[H\033[2J";

        std::cout << std::format(
            "═══════════════════════════════════\n"
            "  STELLAR MERCHANT\n"
            "═══════════════════════════════════\n"
            "  Welcome, Commander.\n"
            "  Select an option to begin:\n\n"
            "  [{}] New Game\n"
            "  [{}] Quit\n"
            "═══════════════════════════════════\n",
            "n", "q"
            );
    }

    void TerminalRenderer::renderAvailableActions(const std::vector<Command>& actions) const
    {
        std::cout << "  Available actions:\n";

        for (auto const& action : actions)
        {
            switch (action)
            {
            case Command::Travel:
                std::cout << std::format("  [{}] Travel to another system\n", 1);
                break;
            case Command::Buy:
                std::cout << std::format("  [{}] Buy cargo / upgrades\n", 2);
                break;
            case Command::Sell:
                std::cout << std::format("  [{}] Sell goods\n", 3);
                break;
            case Command::NewGame:
                std::cout << std::format("  [{}] Start New Game\n", "n");
                break;
            case Command::Quit:
                std::cout << std::format("  [{}] Quit game\n", "q");
                break;
            default:
                // Zabezpieczenie na wypadek dodania nowych komend w przyszłości
                std::cout << "  [-] Unknown Action\n";
                break;
            }
        }

        std::cout << "═══════════════════════════════════\n";
    }
}