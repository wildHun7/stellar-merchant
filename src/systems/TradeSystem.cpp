#include "TradeSystem.h"
#include <format>

namespace sm
{
    Result TradeSystem::buyCommodity(Player& player, const Planet& planet, Commodity cmdty, int quantity)
    {
        // TODO: planet storage validation

        int cmdty_price = planet.getMarket().getPrice(cmdty) * quantity;
        float cmdty_mass = getCommodityInfo(cmdty).mass_per_unit * quantity;

        if (player.getCredits() < cmdty_price)
            return {false, "Not enough credits"};

        if (player.getShip().getAvailableMass() < cmdty_mass)
            return {false, "Not enough load"};

        if(!player.getShip().addCommodity(cmdty, quantity))
            return {false, "Failed to add commodity to cargo"};

        if(!player.spendCredits(cmdty_price))
            return {false, "Failed to spend credits"};

        return {true, std::format("Bought {} units of {} for {} credits", quantity, getCommodityInfo(cmdty).name, cmdty_price)};
    }

    Result TradeSystem::sellCommodity(Player& player, const Planet& planet, Commodity cmdty, int quantity)
    {
        int cmdty_price = planet.getMarket().getPrice(cmdty) * quantity;

        if(player.getShip().getQuantity(cmdty) < quantity)
            return {false, "Not enough commodity in cargo"};

        if(!player.getShip().removeCommodity(cmdty, quantity))
            return {false, "Failed to sell commodity to cargo"};

        player.addCredits(cmdty_price);

        return {true, std::format("Sold {} units of {} for {} credits", quantity, getCommodityInfo(cmdty).name, cmdty_price)};
    }
};
