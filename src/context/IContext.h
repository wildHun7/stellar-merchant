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

    public slots:
        virtual void onTravelRequested(Player& player, const Galaxy& galaxy, int current_system_id, int target_system_id) {}
        virtual void onBuyRequested(Player& player, Planet& planet) {}
        virtual void onSellRequested(Player& player, Planet& planet) {}

    signals:
        void contextChangeRequested(ContextType context_type);
        void actionCompleted(const Result& result);
        void stateChanged();
    };
}
