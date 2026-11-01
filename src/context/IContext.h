#pragma once

#include <QObject>
#include "domain/ContextType.h"
#include "domain/Result.h"
#include "entities/Player.h"
#include "world/Galaxy.h"

namespace sm
{
    class IContext : public QObject
    {
        Q_OBJECT
    public:
        explicit IContext(QObject* parent = nullptr) : QObject(parent) {}
        virtual ~IContext() = default;

        virtual void onEnter(Player&, const Galaxy&, int /*current_system_id*/) {}

    public slots:
        virtual void onTravelRequested(Player& player, const Galaxy& galaxy, int current_system_id, int target_system_id) {}
        virtual void onBuyRequested(Player& player, Planet& planet, sm::Commodity commodity, int quantity) {}
        virtual void onSellRequested(Player& player, Planet& planet, sm::Commodity commodity, int quantity) {}

    signals:
        void contextChangeRequested(ContextType context_type);
        void departureRequested(int target_system_id);
        void systemChanged(int system_id);
        void actionCompleted(const Result& result);
        void stateChanged();
    };
}
